#pragma once

#include <Windows.h>
#include <stdexcept>

namespace test {

// ֱ��ȥ���ϰ�ҳ����ռ�
inline void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux��brk mmap��
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
		// ���Ȱѻ������ڴ������ٴ��ظ�����
		T* obj = nullptr;
		if (_freeList)
		{
			//	ͷɾ
			void* next= *(void**)_freeList;
			obj = (T*)_freeList;
			_freeList = next;

		}
		else
		{
			// ʣ���ڴ治��һ�������Сʱ�������¿����ռ�
			if (_remainBytes < sizeof(T))
			{
				_remainBytes = 1024 * 128;
				//_memory = (char*)malloc(_remainBytes);
				_memory = (char*)SystemAlloc(_remainBytes >> 13);	// ��ҳ�����ڴ�
			}

			obj = (T*)_memory;
			size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);	//�����ڴ�ռ������ڻ����һ��ָ��Ŀռ�
			_memory += objSize;
			_remainBytes -= objSize;
		}

		// ��λnew����ʾ����T�Ĺ��캯����ʼ��
		new(obj)T;
		return obj;
	}

	void Delete(T* obj)
	{
		// ��ʾ�������������������
		obj->~T();
		
		//	ͷ��
		*(void**)obj = _freeList;	//	ȡǰ�Ļ�˸��ֽ�
		_freeList = obj;
	}

private:
	char* _memory = nullptr;	//	ָ�����ڴ��ָ��
	size_t _remainBytes = 0;	//	����ڴ�ָ������ʣ����ֽ���

	void* _freeList = nullptr;	//	���������ڴ�����������ӱ��ͷָ����������
};

}


