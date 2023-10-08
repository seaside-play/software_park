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
