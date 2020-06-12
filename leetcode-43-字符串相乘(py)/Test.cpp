给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入 : num1 = "2", num2 = "3"
输出 : "6"

示例 2 :
输入 : num1 = "123", num2 = "456"
输出 : "56088"

//解题思路
//做一个列表，长度为len(num1) + len(num2), 这个长度为最后两个数相乘的最高位数
//利用列竖式的原理往相应位置填入相应数字


class Solution :
	def multiply(self, num1: str, num2 : str)->str :
if len(num1) < len(num2) : #让num1保持更长
	num1, num2 = num2, num1
	l1, l2 = len(num1), len(num2)
	ans = [0] * (l1 + l2) #做存放最终结果的列表
for i in range(l2 - 1, -1, -1) : #小数字每个位置数字开始乘，从低位开始
for j in range(l1 - 1, -1, -1) :
a = int(num1[j]) * int(num2[i])
count = a // 10 #进位
s = a % 10
ans[l1 - i - 1 + l2 - j - 1] += s
ans[l1 - i + l2 - j - 1] += count
for i in range(len(ans)) : #对最终数字整理
if ans[i] >= 10:
count = ans[i]//10
ans[i] = str(ans[i] % 10)
ans[i + 1] += count
else:
ans[i] = str(ans[i])
ans.reverse()
res = ''.join(ans).lstrip('0') #去掉最前端的0
return  res if len(res) != 0 else '0'

