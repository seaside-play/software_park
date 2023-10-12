## 1 接口定义 ##

- rows：表述记录的总数
- cols：表示每个记录由多少项组成

### 1.1 初始化坐标点的数据
`void IniteAllCoordinatePoint(int* point_arr, int rows, int cols);`  

- point_arr数据内容

给出所有pin坐标、过孔中心坐标、多边形顶点坐标，统一放在一维数组中，如下所示：

`x1 y1`  
`x2 y2`  
`...`  
`x35000 y35000`  

### 1.2 初始化Pin特征的数据
`void InitPinFeature(int* pin_arr, int rows, int cols);`  

- pin_arr数据内容
  
给出器件pin脚的索引值，虚拟网络id，layer_id，统一放在一维数组中，如下所示：

`i10 virtual_net_id_1 layer_id_1`  
`i9 virtual_net_id_2 layer_id_1`  
`...`  
`im virtual_net_id_3 layer_id_7`  


### 1.3 初始化Via特征的数据  
`void InitViaFeature(int* via_arr, int rows, int cols);`  

- via_arr数据内容

给出过孔中心点的索引，顶层的图层id和底层的图层id，统一放在一维数组中，如下所示

`i8 up_layer_id_1 down_layer_id_3`  
`i27 up_layer_id_5 down_layer_id_7`  
`...`  
`i35000 up_layer_id_7 down_layer_id_9`  


### 1.4 初始化多边形特征的数据
`void InitPolygonFeature(int* polygon_arr, int rows);`  

- polygon_arr数据内容

给出多边形顶点数，各个多边形的顶点编号，多边形所在的图层id，统一放在一维压缩数组中，如下所示

`polygon_vertex_count_1 i2 i3 i4 ... i9 layer_id_1`  
`polygon_vertex_count_2 i25 i26 i27 ... i29 layer_id_1`  
`...`  
`polygon_vertex_count_100 i42 i43 i44 ... i49 layer_id_6` 


### 1.5 请求计算网络连通性 
`void RequestCalculateNetConnectivity();`  

### 1.6 获得Via的虚拟网路id
`void GetViaVirtualNetId(int* ret_arr);`  

- ret_arr数据内容：

结果为过孔图形的虚拟网路id，由Fortran端提供计算结果，长度为`void InitViaFeature(int* via_arr, int rows, int cols);`中所提供的rows数据

### 1.7 获得多边形虚拟网络id
`void GetPolygonVirtualNetId(int* ret_arr);` 

- ret_arr数据内容

结果为多边形的虚拟网络id，由Fortran端提供计算结果，长度为`void InitPolygonFeature(int* polygon_arr, int rows);`中所提供的rows数据 

## 2 内存使用原则

谁申请谁释放

  - 4个Init接口，由C++端申请内存，提供数据供Fortran端使用，当Fortran端用完之后，由C++端释放存放数据的内存空间；
  - 2个Get接口，由Fortran端申请内存，提供数据供C++端使用，当C++端用完之后，由Fortran端释放存放数据的内存空间；


