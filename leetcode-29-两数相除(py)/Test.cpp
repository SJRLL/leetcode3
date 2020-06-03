给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

//解题思路
//直接粗暴递归求解

class Solution :
	def divide(self, dividend: int, divisor : int) -> int :
	def divide(a, b) :
if a<b :
	return 0
	flag = 1
	bb = b
while bb + bb<a :
	flag += flag
	bb += bb
	return flag + divide(a - bb, b)

if divisor == 0 :
return dividend
elif divisor == 1 :
return dividend
elif divisor == -1 :
if dividend == -2 * *31 :
return 2 * *31 - 1
else :
return -dividend

a = dividend if dividend>0 else - dividend
b = divisor if divisor>0 else - divisor
re = divide(a, b)
if (dividend>0 and divisor<0) or(dividend<0 and divisor>0) :
	return -re
else:
return re

