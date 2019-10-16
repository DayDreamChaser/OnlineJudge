# -*- coding:UTF-8 -*-
""" 根据输入转换WIFI密码.
输入第一行给出一正整数N(≤100),随后N行,每行按照[编号-答案 ]的格式
给出一题的4个选项,T表示正确,F表示错误。选项间用空格分隔。    """

num = int( input() )
options = {  chr(ord('A')+i):i+1 for i in range(4)  }
codes = []
while ( num > 0 ):
    num = num - 1
    ansline = input()
    pos = ansline.find("T")
    result_char = ansline[pos-2]
    # 输出对应wifi密码位
    if result_char in options:
        codes.append( options[result_char] )
codes = list( map( str, codes ) )
wifi_code = "".join(codes)      
print(wifi_code)
    