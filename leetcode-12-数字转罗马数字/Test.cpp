给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

//解题思路
//整数转罗马数字
{ 1:"I", 5 : "V", 10 : "X", 50 : "L", 100 : "C", 500 : "D", 1000 : "M",
4 : "IV", 9 : "IX", 40 : "XL", 100 : "XC", 400 : "CD", 900 : "CM" }


class Solution :
	def intToRoman(self, num: int)->str :

	m = num // 1000  # 千分位
	l = num % 1000 // 100  # 百分位
	x = num % 1000 % 100 // 10  # 十分位个数
	i = int(str(num)[-1])   # 个位数
	print(m, l, x, i)
# 千
	value = "M" * m
# 百
if l == 4:
value += "CD"
elif l == 9 :
value += "CM"
else:
if l < 5 :
	value += l * "C"
else :
value += "D" + (l - 5) * "C"
# 十
if x == 4:
value += "XL"
elif x == 9 :
value += "XC"
else:
if x < 5 :
	value += x * "X"
else :
value += "L" + (x - 5) * "X"

# 个
if i == 4:
value += "IV"
pass
elif i == 9 :
value += "IX"
else:
if i < 5 :
	value += "I"*i
else :
value += "V" + (i - 5)*"I"

return value

