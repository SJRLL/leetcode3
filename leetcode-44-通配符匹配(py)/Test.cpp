给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明 :

s 可能为空，且只包含从 a - z 的小写字母。
p 可能为空，且只包含从 a - z 的小写字母，以及字符  ? 和 *。
示例 1 :

输入 :
	s = "aa"
	p = "a"
输出 : false
 解释 : "a" 无法匹配 "aa" 整个字符串。
  示例 2 :

输入 :
	s = "aa"
	p = "*"
输出 : true
 解释 : '*' 可以匹配任意字符串。
  示例 3 :

输入 :
	s = "cb"
	p = "?a"
输出 : false
 解释 : '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
  示例 4 :

输入 :
	s = "adceb"
	p = "*a*b"
输出 : true
 解释 : 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
  示例 5 :

   输入 :
	  s = "acdcb"
	  p = "a*c?b"
  输出 : false

//解题思路
//最开始觉得用动态规划很方便，当时超出时间限制了，所以尝试用动态规划做
//这题的初始条件设置比较麻烦，也就是ans[0][j]和ans[j][0]的情况，设置好了就比较好写代码了

class Solution :
	   def isMatch(self, s: str, p : str) -> bool :
   if not s : #s为空的情况
	   return not p.strip('*')
   if not p : #p为空的情况
	   return not s
	   ans = [[False] * len(p) for _ in range(len(s))] #设置动态规划表
   if p[0] in(s[0], '?', '*') : #设置初始值
	   ans[0][0] = True
   for j in range(len(p)) :
   for i in range(len(s)) :
	   firstmatch = p[j] in(s[i], '*', "?") #观察尾部最后一个值是否匹配
   if p[j] == '*': #当p尾部值为‘*’时
   if j - 1 >= 0 and i - 1 >= 0: #当比对的两字符串大小都大于1时，此处状态可以取决于ans[i][j - 1]和ans[i - 1][j]
	   ans[i][j] = ans[i][j - 1] or ans[i - 1][j]
	   elif j - 1 >= 0 and i - 1 < 0: #当s只有1个字符，而p大于1个，其值可以通过strip‘*’来获得此时状态
	   ans[i][j] = (not p[:j + 1].strip('*')) or p[:j + 1].strip('*') in(s[i], '?')
	   elif i - 1 >= 0 and j - 1 < 0: #当s字符大于1，而p为1时
	   ans[i][j] = True
   else: #p尾部不为‘*’的情况
   if j - 1 >= 0 and i - 1 >= 0:
   ans[i][j] = firstmatch and ans[i - 1][j - 1]
	   elif j - 1 >= 0 and i - 1 < 0 : #当s只有1个字符，而p大于1个字符，通过lstrip‘*’获得此时状态
	   ans[i][j] = not p[:j].lstrip('*') and firstmatch
	   elif i - 1 >= 0 and j - 1 < 0:
   ans[i][j] = False
	   return ans[i][j]

