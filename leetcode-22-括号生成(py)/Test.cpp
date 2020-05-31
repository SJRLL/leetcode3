数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


示例：
输入：n = 3
输出：[
	"((()))",
		"(()())",
		"(())()",
		"()(())",
		"()()()"
]

//解题思路
//1.传入根结点
//2.生成决策树
//3.减枝

class Solution :
		def generateParenthesis(self, n: int)->List[str] :
		res = []                                          # 定义全局变量保存最终结果
		path = ''                                         # 定义状态变量保存当前状态
		self.dfs(res, n, n, path)                            # 定义（传入）条件变量（一般条件变量为题目直接给的参数）
		return res

		def dfs(self, res, left, right, path) : # 函数定义：（全局状态变量，条件变量1，条件变量2，当前状态变量）
if left == 0 and right == 0:                      # 满足最终条件
		res.append(path)                              # 加入结果
		return
if left > 0:                                      # 主要递归过程，满足执行条件：左括号个数小于n
		self.dfs(res, left - 1, right, path + '(')
if left < right:                                  # 主要递归过程，满足执行条件：左括号个数大于右括号个数                              self.dfs(res, left, right - 1, path + ')')
