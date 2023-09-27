# 1 确定器件所在的层
## 1.1 思路
1. 获得map和conn数据，得到了层的信息关系；
2. 获得器件的数据，获得每个器件对应的pin脚信息（包括了pin名字，pin id，坐标x和y，网路名和网页id）；
3. 获得gds原始数据；
	1. map的信息，获得顶层或底层的层id；
	2. 从层id获得相应层的几何图形的中心点，并构成有序序列；
	3. 获取器件的坐标点，并转化为整型数据，并构成有序序列；
	4. 比较包含关系，确定该器件所在的层；
		1. 外循环为各个层的数据点，内循环为所有器件的坐标信息；
		2. 确定器件所在的层；

## 1.2 代码接口

1. 创建器件定位器，输出结果为器件名和层id。
	1. 测试性能，使用移位和直接使用字符串作为key值；1000,000的数据量来测试性能；
		1. 放在set中，使用整数；
		2. 放在set中，使用字符串；
	2. 将html中的坐标点转化为整数；
	3. 收集OutlineBuilder中的几何中心点；
	4. 使用includes获得最终的结果值；

## 1.3单位
To calculate the size of a user unit in meters, divide the second number by the first.
即第二个数除以第一个数，获得米值单位， 例如：
	
	那么实际的米制数据位：boundary中的数据phy的数据即可得到真实的生成数据

	UNITS 10  1e-05
	XY 0:16
	16*10*(1e-05/10)

	UNITS 1  1e-06
	XY 0:156
	156*1*(1e-06/1)
	
	UNITS 0.001 1e-09
	XY 890:140
	以默认方式创建库，那么默认的user unit=1micron and 1000 database units per user unit。
	那么database是user unit的1/1000，即0.001，相应的phyunit为：user unit*database = 1micron*0.001。由此可知米制单位为：phyunit/database unit= 1micron*0.001 / 0.001

	database-unit: 
	phy-unit:

	前一个数据定义了unit单位和database unit之间1:1的关系

### 1.3.1 统一单位
在原来的基础上，再扩展10倍，确保是整数

## 1.4 计算pin脚位置和几何位置

- 对比原始数据，看看是否有多少数据不同？可以用集合操作来完成；
	- 可以看到对整数只差1个数据，是因为精度引起的。只要对其除以10，再进行四舍五入操作，就可以完成数据的统一性处理，甚至是归一化处理。这个办法好。
	- 存在的问题：若数据位8104和8105，则divide by 10, 810和811, 这个时候，还需要做另一个判断：即相差1，可认为相同。
- 从原始图中查看坐标的对应关系；（不再需要）
- 利用includes再次判断；（根据stl::includes函数，仿写了一个，在只差1的情况下判断为相同。前提是先对数据排序，之后进行比较，时间复杂度就是O(n)）
- 利用boost中几何功能，完成包含性判断。（不再需要）

## 1.5 测试不同的pin脚报告的单位以及坐标信息

centimeters
inches
microns
mils
millimeters（已解决）

还可能有nanos

