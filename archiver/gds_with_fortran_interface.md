## 1 接口定义 ##

- rows：表述记录的总数
- cols：表示每个记录由多少项组成

### 1.1 初始化坐标点的数据
`void IniteAllCoordinatePoint(const int point_arr[], int rows, int cols);`  

- point_arr数据内容

给出所有pin坐标、过孔中心坐标、多边形顶点坐标以及trace的坐标点，统一放在一维数组中，如下所示：

`x1 y1`  
`x2 y2`  
`...`  
`x35000 y35000`  

### 1.2 初始化Pin特征的数据
`void InitAllPin(const int pin_arr[], int rows, int cols);`  

- pin_arr数据内容
  
给出器件pin脚的索引值，虚拟网络id，layer_id，统一放在一维数组中，如下所示：

`i10 virtual_net_id_1 layer_id_1`  
`i9 virtual_net_id_2 layer_id_1`  
`...`  
`im virtual_net_id_3 layer_id_7`  


### 1.3 初始化Via特征的数据  
`void InitViaFeature(int via_arr[], int rows, int cols, int ret[]);`  

- via_arr数据内容

给出过孔中心点的索引，顶层的图层id和底层的图层id，统一放在一维数组中，如下所示

`i8 up_layer_id_1 down_layer_id_3`  
`i27 up_layer_id_5 down_layer_id_7`  
`...`  
`i35000 up_layer_id_7 down_layer_id_9`  

- ret数据内容
  
将via的网络信息存放在该数组中

### 1.4 初始化多边形特征的数据
`void InitPolygonFeature(int polygon_arr[], int rows);`  

- polygon_arr数据内容

给出多边形顶点数，各个多边形的顶点编号，多边形所在的图层id，统一放在一维压缩数组中，如下所示

`polygon_vertex_count_1 i2 i3 i4 ... i9 layer_id_1`  
`polygon_vertex_count_2 i25 i26 i27 ... i29 layer_id_1`  
`...`  
`polygon_vertex_count_100 i42 i43 i44 ... i49 layer_id_6` 

- ret数据内容
  
将多边形的网络信息存放在该数组中


### 1.5 初始化trace特征的数据
`void InitAllTrace(const int trace_arr[], int rows, int cols, int ret[]);`  

- trace_arr数据内容

给出trace类型，width，点个数，具体的点编号，层id，统一放在一维压缩数组中，格式如下：

`trace_type width trace_point_total_counts i2 i3 i4 ... i9 layer_id_1`  

其中：
`trace_type`: 0: 表示Flush； 1：表示Round

具体例子：
 `1 5000 10 1378 1379 1380 1381 1382 1383 1384 1385 1386 1387 1`

- ret数据内容
  
将trace的网络信息存放在该数组中

### 1.6 请求计算网络连通性 
`void RequestToAnalyseNetId();`  

Fortran端在该接口中执行分析网络id的逻辑，网络结果数据分别放在via、polygon和trace的返回数组中。

## 2 内存使用原则

谁申请谁释放

  - 5个Init接口，由C++端申请内存，提供数据供Fortran端使用，当Fortran端用完之后，由C++端释放存放数据的内存空间；


