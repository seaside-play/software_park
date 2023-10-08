- gds尺寸换算方式

GDS文件中规定的单位：UNITS 10 1e-05 UNITS [first] [second]  
x，y：表示坐标点数据  
实际尺寸计算公式：x*10*（second / first）= x * 10 * (second / 10) = x * second  