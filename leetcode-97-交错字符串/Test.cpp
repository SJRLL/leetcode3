
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入 : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出 : true
	 示例 2 :

 输入 : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
  输出 : false

//思路一 : 动态规划
//自底向上
//动态方程 :
//用dp[i][j]表示s1的前i元素和s2前j元素是否交错组成s3前i + j元素
//所以有动态方程 :
//dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
//注意 : 针对第一行, 第一列要单独考虑
//自顶向下

class Solution :
		def isInterleave(self, s1: str, s2 : str, s3 : str) -> bool :
		 n1 = len(s1)
		 n2 = len(s2)
		 n3 = len(s3)
	 if n1 + n2 != n3 : return False

		 dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]

		 dp[0][0] = True
# 第一行
	 for j in range(1, n2 + 1) :
		 dp[0][j] = (dp[0][j - 1] and s2[j - 1] == s3[j - 1])

# 第一列
	 for i in range(1, n1 + 1) :
		 dp[i][0] = (dp[i - 1][0] and s1[i - 1] == s3[i - 1])
# print(dp)

	 for i in range(1, n1 + 1) :
	 for j in range(1, n2 + 1) :
		 dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or(
		 dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
# print(dp)
		 return dp[-1][-1]

