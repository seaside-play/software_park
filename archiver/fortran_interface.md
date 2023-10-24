### 1.1 初始化坐标点的数据
`void IniteAllCoordinatePoint(int point_arr[], int rows, int cols);`  

### 1.2 初始化Pin特征的数据
`void InitPinFeature(int pin_arr[], int rows, int cols);`  

### 1.3 初始化Via特征的数据  
`void InitViaFeature(int via_arr[], int rows, int cols);`  

### 1.4 初始化多边形特征的数据
`void InitPolygonFeature(int polygon_arr[], int rows);`  
 
### 1.5 请求计算网络连通性 
`void RequestCalculateNetConnectivity();`  

### 1.6 获得Via的虚拟网路id
`void GetViaVirtualNetId(int** via_net_id_arr, int* ret_arr_length);`  

### 1.7 获得多边形虚拟网络id
`void GetPolygonVirtualNetId(int** polygon_net_id_arr, int* ret_arr_length);` 

### 1.8 通知fortran释放返回值的内存 ###

`void ReleaseMemoryResource()`
