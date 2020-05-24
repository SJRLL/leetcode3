给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入 : "babad"
 输出 : "bab"
  注意 : "aba" 也是一个有效答案。
	   示例 2：

   输入 : "cbbd"
	输出 : "bb"

//解题思路：
//如果采取两重循环查找，可以考虑从最大到最小的方向。
//从len(s)到0，每个长度下，遍历所有可能，第一次找到的子串就是最大子串。

class Solution :
	def longestPalindrome(self, s: str)->str :

for i in range(len(s)) :
for l in range(i + 1) :
r = i - l
temp = s[l:len(s) - r]
	if temp == temp[:: - 1] :
		return temp
		return ''

