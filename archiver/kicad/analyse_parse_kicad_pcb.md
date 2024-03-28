分析kicad_pcb文件

# kicad_pcb文件

内容简单示例

    (kicad_pcb
      (version 20240108)
      (generator "pcbnew")
      (generator_version "8.0")
      (general
        (thickness 1.6)
        (legacy_teardrops no)
      )
      (paper "A4")
      (layers
        (0 "F.Cu" signal)
      ）
    ）


所有的关键字都对应一个枚举值

如`kicad_pcb`是某一个文件类型的识别码，也对应一个枚举值`T_kicad_pcb`
如`version`对应了一个枚举值`T_via`

string为utf-8内容，那么可以将string转化成wxString，函数为：`wxString::FromUTF8( curText.c_str() );`

- `pcb_io_kicad_sexpr_parser.cc`： 在该类中，解析了所有的kicad_pcb的数据·
  - line:910: 在该for循环中，解析出version之后的所有内容
    - _fgetc_nolock：读取字符，单线程速度更快
- `dsnlexer.cpp`
  - line:518: NextTok()
    - 解析下一个token，在获取token的同时，也分析出了当前行的数据、下一个要分析的字符串，长度等信息
    - 不仅获得整个一行的数据，而获得该行结尾之后的下一个非数据，一个一个读取字符；
    - 对每个字符区分四种情况：
      - 空格类的字符：如\t,\n,\r,\0
      - token类的字符：如左右圆括号
      - 注释类的字符：#
      - 实际的关心的内容：
        - 预先执行了枚举化
      - 利用limit：来获取下一组数据，以及求解当前组数据
    - line：773
      - 要开发分析当前字符串了，先保留当前字符串的头指针
      - 若不是space和左右括号，就一直移动head，并且将当前head的字符添加到curText中，这种操作太棒啦！由此，获得key值
      - 由该第一个值，即key值，获得对应的类型索引号
    - token和symbol之间的区别
      - 由代码可知，左右括号，第一个关键字，都被设置为token；
      - token：专门区分各个数据
      - left：左括号
      - right：右括号
      - symbol：专门指左右括号内的数据划分
      - 从取值来看，分成负数和正数两大类型
    - line：614，分析key之后的数据
    - 当cur的指针地址大于limit之后，就会读取下一行的数据