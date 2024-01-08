#pragma once

#include <Windows.h>
#include <stdexcept>

namespace test {



// ֱ��ȥ���ϰ�ҳ����ռ�
inline void* SystemAlloc(size_t kpage) {
#ifdef _WIN32
  void* ptr =
      VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
  // linux��brk mmap��
#endif

  if (ptr == nullptr)
    throw std::bad_alloc();

  return ptr;
}

template <class T>
class SimpleMemoryPool {
 public:
  T* New() {
    // ���Ȱѻ������ڴ������ٴ��ظ�����
    T* obj = nullptr;
    if (free_list_) {
      //	ͷɾ
      void* next = *(void**)free_list_;
      obj = (T*)free_list_;
      free_list_ = next;

    } else {
      // ʣ���ڴ治��һ�������Сʱ�������¿����ռ�
      if (remain_bytes_ < sizeof(T)) {
        remain_bytes_ = 1024 * 128;
        //_memory = (char*)malloc(_remainBytes);
        memory_ = (char*)SystemAlloc(remain_bytes_ >> 13);  // ��ҳ�����ڴ�
      }

      obj = (T*)memory_;
      size_t objSize =
          sizeof(T) < sizeof(void*)
              ? sizeof(void*)
              : sizeof(T);  //�����ڴ�ռ������ڻ����һ��ָ��Ŀռ�
      memory_ += objSize;
      remain_bytes_ -= objSize;
    }

    // ��λnew����ʾ����T�Ĺ��캯����ʼ��
    new (obj) T;
    return obj;
  }

  void Delete(T* obj) {
    // ��ʾ�������������������
    obj->~T();

    //	ͷ��
    *(void**)obj = free_list_;  //	ȡǰ�Ļ�˸��ֽ�
    free_list_ = obj;
  }

 private:
  char* memory_ = nullptr;  //	ָ�����ڴ��ָ��
  size_t remain_bytes_ = 0;  //	����ڴ�ָ������ʣ����ֽ���

  void* free_list_ = nullptr;  //	���������ڴ�����������ӱ��ͷָ����������
};

}  // namespace test