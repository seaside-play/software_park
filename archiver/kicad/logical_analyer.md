# CN_LIST
在`CN_LIST`中添加item元素时，会认为数据是脏的，不干净的。不仅添加到vector中，还添加到rtree对象中，便于索引。

用电气元素构建item之后，又将电气元素和item元素关联起来，并通过中间的封装类来进行关联。

Kicad中Pad和Trace判断是否相交，以确定是否显示Pad。此时的Trace和Pad的过是否相交，若相交，才显示Pad。