STL之heap使用简介
STL中并没有把heap作为一种容器组件，heap的实现亦需要更低一层的容器组件（诸如list,array,vector）作为其底层机制。Heap是一个类属算法，包含在algorithm头文件中。虽然STL中关于heap默认调整成的是大顶堆，但却可以让用户利用自定义的compare_fuction函数实现大顶堆或小顶堆。heap的低层机制vector本身就是一个类模板，heap基于vector便实现了对各种数据类型（无论基本数据类型还是用户自定义的数据类型）的堆排（前提是用户自定义的数据类型要提供比较机制compare_fuction函数）。
 
STL里面的堆操作一般用到的只有4个。
make_heap();pop_heap();push_heap();sort_heap();
 
make_heap();
函数原型是：
void make_heap(first_pointer,end_pointer,compare_function);
一个参数是数组或向量的头指针，第二个向量是尾指针。第三个参数是比较函数的名字。在缺省的时候，默认是大跟堆。（下面的参数都一样就不解释了）
 
作用：把这一段的数组或向量做成一个堆的结构。范围是(first,last)
 
pop_heap();
函数原型是：
void pop_heap(first_pointer,end_pointer,compare_function);
 
作用：pop_heap()不是真的把最大（最小）的元素从堆中弹出来。而是重新排序堆。它把first和last交换，然后将[first,last-1)的数据再做成一个堆。
 
push_heap()
void push_heap(first_pointer,end_pointer,compare_function);
 
作用：push_heap()假设由[first,last-1)是一个有效的堆，然后，再把堆中的新元素加进来，做成一个堆。
 
sort_heap()
void sort_heap(first_pointer,end_pointer,compare_function);
 
作用是sort_heap对[first,last)中的序列进行排序。它假设这个序列是有效堆。（当然，经过排序之后就不是一个有效堆了）




#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b) //比较函数
{
   return a>b;
}

int main()
{
    int i,number[20]={29,23,20,22,17,15,26,51,19,12,35,40};
    make_heap(&number[0],&number[12]);
    //结果是:51 35 40 23 29 20 26 22 19 12 17 15
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");
    make_heap(&number[0],&number[12],cmp);
    //结果：12 17 15 19 23 20 26 51 22 29 35 40
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");

    //加入元素8
    number[12]=8;
    //加入后调整
    push_heap(&number[0],&number[13],cmp);
    //结果：8 17 12 19 23 15 26 51 22 35 40 20
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    printf("\n");

    //弹出元素8
    pop_heap(&number[0],&number[13],cmp);
    //结果：12 17 15 19 23 20 26 51 22 29 35 40
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    printf("\n");

    sort_heap(&number[0],&number[12],cmp);
    //结果不用说都知道是有序的了！
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    return 0;
}