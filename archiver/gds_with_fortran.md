#  设计与fortran之间的交互设计  # 

需要统一坐标尺寸

## 1 器件 ##

给出所有器件pin脚的坐标，给出坐标的索引、虚拟网络id和层id，分别构成两个二维数值，如下：

`x1,y1`   
`x2,y2`  
`...`  
`xn...yn`


`i1,virtual_net_id, layer_id`  
`i2,virtual_net_id, layer_id`  
`...`  
`in,virtual_net_id, layer_id`  

## 2 过孔层 ##

给出所有过孔层上的过孔中心点坐标，给出相应坐标的索引id和层id，分别构成两个二维数组，如下：

`x1,y1`   
`x2,y2`  
`...`   
`xn...yn`  

`i1,layer_up_id, layer_down_id`  
`i2,layer_up_id, layer_down_id`  
`...`  
`in,layer_up_id, layer_down_id`  

考虑到多个过孔层可能存在多个相同的点，所以使用坐标+索引的方式，以减少数据量。当然可以给出所有的x，y和上下层id。

### 2.1 过孔层几何中心和图层id

- 设计思路

1. 根据conn文件获得，过孔层和上下层之间的id
2. 根据过孔层的id，获取相应的几何中心点
3. 并导出via.txt文件，包含所有过孔层中几何中心点，以及索引id和上下层layer_id

## 3 各图层几何图形 ##

给出每个层的几何图形的顶点，给出每个层的各个Polygon的坐标点索引值，分别构成两个二维数组，如下：

`x1,y1`   
`x2,y2`  
`...`  
`xn...yn`

`i1, i2, ..., im`  
`i3, i4, ..., in`  
`...`  
`i11, i22, ..., ix`  

## 4 接口数据

### 4.1 坐标二维数据 ###

将所有pin坐标、过孔中心坐标、多边形顶点坐标，统一放在一个二维数组中，构成一个接口，二维数组如下示例：

`x1 y1`  
`x2 y2`  
`...`  
`x35000 y35000`  

### 4.2 器件Pin二维数据 ###

给出器件pin脚的索引值，虚拟网络id，layer_id，二维数组如下示例：

`i10 virtual_net_id_1 layer_id_1`  
`i9 virtual_net_id_2 layer_id_1`  
`...`  
`im virtual_net_id_3 layer_id_7`  


### 4.3 过孔中心二维数据 ###

`i8 up_layer_id_1 down_layer_id_3`  
`i27 up_layer_id_5 down_layer_id_7`  
`...`  
`i35000 up_layer_id_7 down_layer_id_9`  


### 4.4 各图层多边形顶点二维数据 ###

`vertex_count1 i2 i3 i4 ... i9 layer_id_1 layer_id_2`  
`vertex_count100 i25 i26 i27 ... i29 layer_id_1 layer_id_3`  
`...`  
`vertex_count200 i42 i43 i44 ... i49 layer_id_6 layer_id_5`  


## 5 接口设计 ##

void GetAllCoordinatePoint(int* coordinate, int rows);
bool BuildVirtualNetIdForVia(int* vid_ret, int* via_2d_arr, int rows, int cols);
bool BuildVirtualNetIdForPolygon(int* vid_ret, int* polygon_2d_arr, int rows, int cols);


