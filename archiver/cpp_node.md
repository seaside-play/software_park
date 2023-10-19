- 运算效率
  
  `移位 > 赋值 > 大小比较 > 加法 > 减法 > 乘法 > 取模 > 除法`

- binary_search()

需要注意的是，由于 binary_search() 底层实现采用的是二分查找的方式，因此该函数仅适用于“已排好序”的序列。所谓“已排好序”，并不是要求 [first, last) 区域内的数据严格按照某个排序规则进行升序或降序排序，`只要满足“所有令 element<val（或者 comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）”即可。`

那么就意味着，在默认情况下，comp中的lhs参数是所有element中的最大值。

关联容器将以下算法函数列为成员函数，也可单独使用，而顺序容器则需要`algorithm`来执行
`binary_saerch()` , `equal_range`, `lower_bound`, `upper_bound` 