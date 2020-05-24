给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1 :

输入 : 123
输出 : 321
	 示例 2 :

 输入 : -123
  输出 : -321
	   示例 3 :

   输入 : 120
	输出 : 21

//解题思路
//python代码实现，基本的思路是，首先将判断输入x的符号，有正、负和0。处理0时，直接定义为0：num_sum = 0。处理正负时，将数据转化为正数，其中flag作为符号。翻转的思路是 : 依次取数据的个位数(x % 10), 然后将其整除10(x//10)。逐步减小数据直到为0，list保存数据，有效的解决个位数为0情况。

class Solution :
	def reverse(self, x: int) -> int :
	flag = 1
if x < 0 :
	flag = -1
	x = -x
	num_list = []

	while x :
		num_list.append(x % 10)
		x = x//10
		num_sum = 0

		num_len = len(num_list)
	for i, item in enumerate(num_list) :
		num_sum += item * 10 * * (num_len - i - 1)

		num_sum = flag*num_sum
	if (num_sum < -2 * *31) or(num_sum >  2 * *31 - 1) :
		return 0
	else:
	return num_sum




