1. 通过闭操作（先膨胀，再腐蚀）将数字连在一起；

  gradX = cv2.morphologyEx(gradX, cv2.MORPH_CLOSE, rectKernel)

2. 过滤轮廓
   得到轮廓特征：外界矩形，算长宽比率（自己调整）

   排序： locs = sorted(locs, key=lambda x: x[0])