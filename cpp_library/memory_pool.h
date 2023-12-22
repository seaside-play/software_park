#pragma once

#include <Windows.h>
#include <stdexcept>

namespace test {

// 直接去堆上按页申请空间
inline void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等
#endif

	if (ptr == nullptr)
		throw std::bad_alloc();

	return ptr;
}


template <class T>
class myObject
{
public: 
	T* New()
	{
		// 优先把还回来内存块对象，再次重复利用
		T* obj = nullptr;
		if (_freeList)
		{
			//	头删
			void* next= *(void**)_freeList;
			obj = (T*)_freeList;
			_freeList = next;

		}
		else
		{
			// 剩余内存不够一个对象大小时，则重新开大块空间
			if (_remainBytes < sizeof(T))
			{
				_remainBytes = 1024 * 128;
				//_memory = (char*)malloc(_remainBytes);
				_memory = (char*)SystemAlloc(_remainBytes >> 13);	// 按页申请内存
			}

			obj = (T*)_memory;
			size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);	//申请内存空间必须大于或等于一个指针的空间
			_memory += objSize;
			_remainBytes -= objSize;
		}

		// 定位new，显示调用T的构造函数初始化
		new(obj)T;
		return obj;
	}

	void Delete(T* obj)
	{
		// 显示调用析构函数清理对象
		obj->~T();
		
		//	头插
		*(void**)obj = _freeList;	//	取前四或八个字节
		_freeList = obj;
	}

private:
	char* _memory = nullptr;	//	指向大块内存的指针
	size_t _remainBytes = 0;	//	大块内存分割过程中剩余的字节数

	void* _freeList = nullptr;	//	还回来的内存块用自由链接表的头指针链接起来
};

}


