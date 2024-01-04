C++经典内存管理之new,malloc的区别及底层原理

这两者都是动态申请内存用的，是很重要也是很容易被考察的知识点，整理如下。

void *malloc (int size);
malloc是一个C里面的库函数，需要加头文件；
可以看出，malloc功能是向系统申请分配size字节的内存空间，返回类型为void *类型；所以我们需要在返回时强制转换一下，不然会出现错误。
并且，free释放的是指针指向的内存空间，指针变量一直存在，直到程序结束。

    int* p;
    p = (int*)malloc(sizeof(int));

    free(p);//释放内存
    int a = 10;
    p = &a;//指针依旧存在且可以被赋值

malloc的底层工作机制。
malloc函数调用时，他将在内存（堆中）的空闲链表（操作系统一种组织可用内存的方式）寻找足够大的空闲区域；
找到的话，它会将符合要求的大小部分返回给用户，剩下的继续回到空闲链表；
如果经过多次调用，空闲区域七零八碎，找不到符合要求的区域，malloc函数请求延时，并开始在空闲链上翻箱倒柜地检查各内存片段，对它们进行整理，将相邻的小空闲块合并成较大的内存块。
如果实在没有空闲内存了，那么会返回NULL指针，所以我们需要判断返回的是否是NULL指针，以此判断是否请求内存成功。

malloc是一个函数，只请求内存，不会有初始化操作。那么对于非内置类型，比如对象，在创建时需要初始化，malloc就无法使用。new/delete就起到作用了。

    //开辟单地址空间
    int *p = new int;  //开辟大小为sizeof(int)空间
    int *q = new int(5); //开辟大小为sizeof(int)的空间，并初始化为5。
    //开辟数组空间
    //一维
    int *a = new int[100]{0};//开辟大小为100的整型数组空间，并初始化为0。

    //链表
    Listnode* node=new Listnode(0);

可以看出，new和malloc的几点区别。
new不需要指定请求内容的大小，自己会判断；
new返回的是指定类型的指针，不需要强制转换；
new需要进行初始化；

new的底层原理。
对于自定义类型（比如对象），new会先调用operator new函数，申请足够的内存（通常底层使用malloc实现）。然后调用类型的构造函数，初始化成员变量，最后返回自定义类型指针。delete先调用析构函数，然后调用operator delete函数释放内存（通常底层使用free实现）。
new分配失败不会返回NULL指针，而是抛出异常。
从这个角度来看，new其实是C++对malloc函数进行了封装和扩展，使其可以进行初始化操作。

另外，关于重载
C++允许重载new/delete操作符，特别的，布局new的就不需要为对象分配内存，而是指定了一个地址作为内存起始区域，new在这段内存上为对象调用构造函数完成初始化工作，并返回此地址。而malloc不允许重载。

所以，C++中，认为new分配的内存是自由存储区，这个不等于堆，堆是操作系统中的概念。比如定位new指定的内存就不属于堆。

下面重点介绍一下Malloc的具体原理

malloc 申请内存的时候，会有两种方式向操作系统申请堆内存。
方式一：申请小于128KB，通过 brk() 系统调用从堆分配内存，将「堆顶」指针向高地址移动，获得新的内存空间.free 释放内存的时候，并不会把内存归还给操作系统，而是缓存在 malloc 的内存池中，待下次使用；
方式二：大于128KB，通过 mmap() 系统调用在文件映射区域分配内存;free 释放内存的时候，会把内存归还给操作系统，内存得到真正的释放。
malloc() 分配的是虚拟内存。
如果分配后的虚拟内存没有被访问的话，虚拟内存是不会映射到物理内存的，这样就不会占用物理内存了。

malloc() 在分配内存的时候，并不是老老实实按用户预期申请的字节数来分配内存空间大小，而是会预分配更大的空间作为内存池。malloc(1) 实际上预分配 132K 字节的内存
为什么不全部使用 mmap 来分配内存？
频繁通过 mmap 分配的内存话，不仅每次都会发生运行态的切换，还会发生缺页中断（在第一次访问虚拟地址后），这样会导致 CPU 消耗较大。

既然 brk 那么牛逼，为什么不全部使用 brk 来分配？
随着系统频繁地 malloc 和 free ，尤其对于小块内存，堆内将产生越来越多不可用的碎片，导致“内存泄露”。而这种“泄露”现象使用 valgrind 是无法检测出来的。
所以，malloc 实现中，充分考虑了 brk 和 mmap 行为上的差异及优缺点，默认分配大块内存 (128KB) 才使用 mmap 分配内存空间。
free() 函数只传入一个内存地址，为什么能知道要释放多大的内存？
free 会对传入进来的内存地址向左偏移 16 字节，然后从这个 16 字节的分析出当前的内存块的大小，自然就知道要释放多大的内存了。

虚拟内存的作用
首先是地址隔离。不同进程可以用同一套虚拟地址，通过页表来映射。这就简化了连接加载，共享，内存分配，编码的过程。
其次是实现了缓存，虚拟内存就是物理内存的一个副本，比磁盘快，而且swap技术可以逻辑上增加虚拟内存的大小。
最后实现了安全限制，比如页表项里面有相关的比特位，代表可读可写，以及内核才能访问等

如果内存紧张会怎么办？
应用程序通过 malloc 函数申请内存的时候，实际上申请的是虚拟内存，此时并不会分配物理内存。
当应用程序读写了这块虚拟内存，CPU 就会去访问这个虚拟内存， 这时会发现这个虚拟内存没有映射到物理内存， CPU 就会产生缺页中断，进程会从用户态切换到内核态，并将缺页中断交给内核的 Page Fault Handler （缺页中断函数）处理。
缺页中断处理函数会看是否有空闲的物理内存，如果有，就直接分配物理内存，并建立虚拟内存与物理内存之间的映射关系。
如果没有空闲的物理内存，那么内核就会开始进行回收内存的工作，回收的方式主要是两种：直接内存回收和后台 kswapd 内存回收。

如果后台的内核线程回收是异步的，不阻塞malloc，还没有足够的空间分配，就会开始直接回收（直接释放或者lru swap），这个回收内存的过程是同步的，会阻塞进程的执行。如果直接内存回收后，空闲的物理内存仍然无法满足此次物理内存的申请，那么内核就会放最后的大招了 ——触发 OOM （Out of Memory）机制。
OOM Killer 机制会根据算法选择一个占用物理内存较高的进程，然后将其杀死，以便释放内存资源，如果物理内存依然不足，OOM Killer 会继续杀死占用物理内存较高的进程，直到释放足够的内存位置（内核有一个函数就是负责给进程打分的，最高的杀掉，分数由进程内存页大小以及一个参数，如果不想系统服务被杀，就设置-100，不会被杀）。

可被回收的内存类型有文件页和匿名页：
文件页的回收：对于干净页是直接释放内存，这个操作不会影响性能，而对于脏页会先写回到磁盘再释放内存，这个操作会发生磁盘 I/O 的，这个操作是会影响系统性能的。
匿名页的回收：如果开启了 Swap 机制，那么 Swap 机制会将不常访问的匿名页换出到磁盘中，下次访问时，再从磁盘换入到内存中，这个操作是会影响系统性能的。
文件页和匿名页的回收都是基于 LRU 算法，也就是优先回收不常访问的内存。回收内存的操作基本都会发生磁盘 I/O 的，如果回收内存的操作很频繁，意味着磁盘 I/O 次数会很多，这个过程势必会影响系统的性能。

在 NUMA 架构下，当某个 Node 内存不足时，系统可以从其他 Node 寻找空闲内存，也可以从本地内存中回收内存。

原文链接：https://blog.csdn.net/weixin_53344209/article/details/127533351