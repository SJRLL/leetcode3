﻿给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入 : "()"
输出 : true

示例 2 :
输入 : "()[]{}"
输出 : true

示例 3 :
输入 : "(]"
输出 : false

示例 4 :
输入 : "([)]"
输出 : false

示例 5 :
输入 : "{[]}"
输出 : true

//解题思路
//当左括号 则记录对于的右括号 比如 字符串 '[]]' ，出现 '[' 则在数组 's_list' 中记录 ']'
//通过 s_list.insert(0, '右括号') 可以保证，每次插入的括号和 左括号对称
//当出现 右括号 则先判断数组 'len(s_list) ==0 ' ，因为有可能出现 '[]]]' 或 ']' 的情况
//当循环中 出现右括号 则和数组中 's_list.pop(0)' 进行对比，如果相同，则对于的删除，继续执行，否则返回false

class Solution(object) :
	def isValid(self, s) :
# 初始化判断条件
if s is None :
return False
if len(s) == 0 :
return True
# 当左括号 则记录对于的右括号
s_list = []
	for a in s :
	if a == '(' :
		s_list.insert(0, ')')
		elif a == '[' :
		s_list.insert(0, ']')
		elif a == '{' :
		s_list.insert(0, '}')
		elif len(s_list) != 0 and a == s_list.pop(0) : # len(s_list) != 0 出现 '[]]'清空的判断
		continue
	else: # 当 不匹配则 返回 False
	return False
	return True # 最后要清空 s_list 才是一个完整的闭环

