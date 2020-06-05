给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1 :

输入 : "(()"
输出 : 2
 解释 : 最长有效括号子串为 "()"
	  示例 2 :

  输入 : ")()())"
   输出 : 4
	解释 : 最长有效括号子串为 "()()"

//解题思路:

//首先初始化栈stack_leftloc, 初始化变量max_length, left_board = 0, -1
//遍历字符串, 当遇到左括号时 :
//将左括号的位置入栈。
//当遇到右括号时, 有下列三种情况 :
//1. 栈空, 说明没有左括号再与该括号匹配, 那么设置left_board = 该右括号的位置, 意思是后续的最长有效括号的 起点无法超过该位置;
//2. 栈不为空, 且超过一个元素, 那么弹出栈顶元素, 并且计算此时的有效括号长度 = index - stack_leftloc[-1];
//3. 栈不为空, 但只有一个元素, 那么弹出栈顶元素, 并且计算此时的有效括号长度 = index - left_board。

class Solution :
	 def longestValidParentheses(self, s: str) -> int :
	 stack_leftloc, max_length, left_board = [], 0, -1
	 dp = [0 for _ in s]
		 for index, char in enumerate(s) :
		 if char == '(' :
			 stack_leftloc.append(index)
		 else :
		 if len(stack_leftloc) == 0 :
			 left_board = index
		 else :
		 left = stack_leftloc.pop()
		 if len(stack_leftloc) == 0 :
			 max_length = max(max_length, index - left_board)
		 else :
		 max_length = max(max_length, index - stack_leftloc[-1])
		 return max_length
