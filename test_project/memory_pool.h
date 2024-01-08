#pragma once

#include <Windows.h>
#include <stdexcept>

namespace test {



// 直接去堆上按页申请空间
inline void* SystemAlloc(size_t kpage) {
#ifdef _WIN32
  void* ptr =
      VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
  // linux下brk mmap等
#endif

  if (ptr == nullptr)
    throw std::bad_alloc();

  return ptr;
}

template <class T>
class SimpleMemoryPool {
 public:
  T* New() {
    // 优先把还回来内存块对象，再次重复利用
    T* obj = nullptr;
    if (free_list_) {
      //	头删
      void* next = *(void**)free_list_;
      obj = (T*)free_list_;
      free_list_ = next;

    } else {
      // 剩余内存不够一个对象大小时，则重新开大块空间
      if (remain_bytes_ < sizeof(T)) {
        remain_bytes_ = 1024 * 128;
        //_memory = (char*)malloc(_remainBytes);
        memory_ = (char*)SystemAlloc(remain_bytes_ >> 13);  // 按页申请内存
      }

      obj = (T*)memory_;
      size_t objSize =
          sizeof(T) < sizeof(void*)
              ? sizeof(void*)
              : sizeof(T);  //申请内存空间必须大于或等于一个指针的空间
      memory_ += objSize;
      remain_bytes_ -= objSize;
    }

    // 定位new，显示调用T的构造函数初始化
    new (obj) T;
    return obj;
  }

  void Delete(T* obj) {
    // 显示调用析构函数清理对象
    obj->~T();

    //	头插
    *(void**)obj = free_list_;  //	取前四或八个字节
    free_list_ = obj;
  }

 private:
  char* memory_ = nullptr;  //	指向大块内存的指针
  size_t remain_bytes_ = 0;  //	大块内存分割过程中剩余的字节数

  void* free_list_ = nullptr;  //	还回来的内存块用自由链接表的头指针链接起来
};

}  // namespace test