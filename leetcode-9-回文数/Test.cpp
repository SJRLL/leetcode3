判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入 : 121
输出 : true
 示例 2 :

  输入 : -121
   输出 : false
	解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
		 示例 3 :

	 输入 : 10
	  输出 : false
	   解释 : 从右向左读, 为 01 。因此它不是一个回文数。

//解题思路 1.0
//若整数为负，则直接返回False
//将整数反转，为避免输入整数在反转过程中被修改，预存一个变量，完成反转操作
//判断反转后的整数是否与原输入整数相同，返回结果

class Solution(object) :
		 def isPalindrome(self, x) :
		 """
		 : type x : int
		 : rtype : bool
		 """

	 if x < 0 :
		 return False

		 num = x
		 num_reverse = 0
		 i = len(str(x))
	 while i > 0:

	 num_reverse = num_reverse * 10 + num % 10
		 num //= 10

		 i -= 1

	 if num_reverse == x:
	 return True
	 else:
	 return False


