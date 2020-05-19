
给定范围[m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1:

输入 : [5, 7]
输出 : 4
	 示例 2 :

 输入 : [0, 1]
  输出 : 0

//解题思路：第一个想法是，brute force(暴力循环)，从头到尾来一遍就行了，就是不知道过不过

class Solution :
	def rangeBitwiseAnd(self, m: int, n : int) -> int :
	result = m
for i in range(m + 1, n + 1) :
	result = result&i
	return result
