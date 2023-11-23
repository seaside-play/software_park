Context（Project::LoadObject）
Project* project：当前类指针
std::string file_name: 加载的文件名
int last_tag_id: 最后一个标签id
CEventMgr event_mgr: used to solve external named_ptr
CPtrList backup_shape_list: CPkgShape

### _malloca _freea

根据此处的参考文档，_malloca**在堆栈上**而**不是在堆上**分配内存。分配数组的大小是相同的。所以你实际上并没有解决任何问题。

警告说分配的数组可能太短了。为什么你会收到这个警告，malloc但_malloca我不知道。但是如果编译器最初是正确的，那么问题仍然存在。

要非常小心_malloca！一旦函数离开其范围，它分配的内存可能会被释放。它必须通过调用来释放_freea。您可能需要仔细阅读此函数的参考文档，并确保您真正了解其中的细节。



  #pragma waring(push)
  #pragma waring(disable：4200)
  #pragma pack(push，4)

  #pragma pack(pop)
  #pragma warning(pop)


  af.x中使用POSTION表示某一个对象的指针，类似于void*
  CPtrListEx就是保存了所有的节点内容的指针，以及next和pre之间的node点，构成一颗树；而CEvntMgr是monitor和event node的结合。