给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明 :

s 可能为空，且只包含从 a - z 的小写字母。
p 可能为空，且只包含从 a - z 的小写字母，以及字符 .和 *。
示例 1 :

输入 :
   s = "aa"
   p = "a"
输出 : false
 解释 : "a" 无法匹配 "aa" 整个字符串。
	  示例 2 :

  输入 :
	 s = "aa"
	 p = "a*"
 输出 : true
  解释 : 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
   示例 3 :

输入 :
	s = "ab"
	p = ".*"
输出 : true
 解释 : ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
	  示例 4 :

  输入 :
	 s = "aab"
	 p = "c*a*b"
 输出 : true
  解释 : 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
	   示例 5 :

   输入 :
	  s = "mississippi"
	  p = "mis*is*p*."
  输出 : false

//解题思路
//复杂dp, 对状态的转移要分情况讨论
//一般两个字符串的dp设计的dp[i][j]都代表前i个str1和前j个str2的关系

   class Solution :
	   def isMatch(self, s: str, p : str) -> bool :
# if not s or not p:
#     return s == p
	   ls, lp = len(s), len(p)
	   dp = [[False] * (ls + 1) for _ in range(lp + 1)] # dp[i][j]代表前i个p可以匹配前j个s
	   dp[0][0] = True
   for i in range(1, lp + 1) :
   if p[i - 1] == '*' :
	   dp[i][0] = dp[i - 1][0] or dp[i - 2][0]
	   for i in range(1, lp + 1) :
	   for j in range(1, ls + 1) :
	   if p[i - 1] == s[j - 1] or p[i - 1] == '.' :
		   dp[i][j] = dp[i - 1][j - 1]
# else:
# if p[i-1]!='*': dp[i][j] = False
	   elif p[i - 1] == '*' :
   if p[i - 2] != s[j - 1] and p[i - 2] != '.' : dp[i][j] = dp[i - 2][j] # 把char*忽略掉
   else :
   dp[i][j] = dp[i - 1][j] or dp[i - 2][j] or dp[i][j - 1] # 分别代表匹配一个char, 匹配0个char, 匹配多个char
   return dp[-1][-1]

