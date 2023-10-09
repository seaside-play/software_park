## 1 gds尺寸换算方式

GDS文件中规定的单位：UNITS 10 1e-05 UNITS [first] [second]  
x，y：表示坐标点数据  
实际尺寸计算公式：`x*10*（second / first）= x * 10 * (second / 10) = x * second`  

## 2 Path中点的存放方式不同

### 2.1 概述 ###
Allegro的gds文件和其它软件导出的gds文件（如：demo.gds或自制的gds），对Path的处理方式不同：

Allegro：Path中的数据是一个trace给出独立的两个点，除首尾点之后，中间的点就出现两份。分别表示前一段trace的结束点，和下一段trace的开始点。  
其它软件导出的（如KLayout或其它前端工具）：Path中的数据点，除首尾之外，既表示前一段的结束点，又表示下一段的开始点。

存在一个Path中，组成的每一小段的width可以不同。

### 2.2 设计 ###


- 思路
   
  在原有逻辑的基础上，增加对内在数据的逻辑判断，若除首尾点之外，存在多于2个点的Path，判断其内在点的组织方式，若两两相等，则认为是Allegro方式，否则是其它方式。

1. Allegro方式：给出成对数据点ABBCCD方式，对应AB，BC，CD方式。ALLEGRO_PAIR
2. 其它方式：给出单点数据方式：ABCD方式，对应AB，BC，CD方式。  SINGLE

 
在真正取点的时候，若是Allegro就跳动三格来获取第三个点，若是其它的组织方式就调动两格，而中点始终是一格。

同时在设置将Path转化为多边形时，取点的个数也需要做相应的调整。否则就会出现（0,0）点。因为在SINGLE时，多边形的点的个数为Path的点的双倍，而以ALLEGRO_PAIR出现时，多边形的点的个数正好为Path中的点的个数。若仍然以双倍计算，就会出现（0,0）点，导致出错。


## 3 设计与fortran之间的接口 ## 

### 3.1 器件 ###

以二维数组的形式提供所有器件的坐标，再以坐标的id，虚拟网络id和层id给出所有pin的信息，即两个二维数组，如下：

`x1,y1`   
`x2,y2`  
`...`  
`xn...yn`


`i1,virtual_net_id, layer_id`  
`i2,virtual_net_id, layer_id`  
`...`  
`in,virtual_net_id, layer_id`  

### 3.2 过孔 ###

同样给出所有的过孔中心点的坐标，再以坐标的id，层的上线id构成另一个二维数组，即两个二维数组，如下：

`x1,y1`   
`x2,y2`  
`...`   
`xn...yn`  


`i1,layer_up_id, layer_down_id`  
`i2,layer_up_id, layer_down_id`  
`...`  
`in,layer_up_id, layer_down_id`  

### 3.1 几何图形 ###

针对每一层，提供该层的所有坐标点，以二维数组的形式出现，同时针对每一个Polygon，其对应的坐标点以索引值的形式给出。

`x1,y1`   
`x2,y2`  
`...`  
`xn...yn`

`i1, i2, ..., im`  
`i3, i4, ..., in`  
`...`  
`i11, i22, ..., ix`  