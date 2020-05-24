将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入 : s = "LEETCODEISHIRING", numRows = 3
输出 : "LCIRETOESIIGEDHN"
 示例 2 :

  输入 : s = "LEETCODEISHIRING", numRows = 4
   输出 : "LDREOEIIECIHNTSG"
	解释 :

	   L     D     R
	   E   O E   I I
	   E C   I H   N
	   T     S     G

//解题思路：
//题目要我们求出一个字符串Z字型变换嘛，那我们就先把它的Z字型矩阵求出来，再依次按行读取相应元素即可得出最终答案，是不是很简单。

	 class Solution :
		 def convert(self, s, numRows) :
	 if numRows <= 1 :
		 return s
		 DecArray = self.getArray(s, numRows)
		 result = ''.join(DecArray.flatten())
		 result = result.replace('-', '')
		 return result

# 构建Z型数组法获得相关数组
		 def getArray(self, s, numRows) :
		 DecArray = np.array([['-'] * len(s)] * numRows)
		 ArrayIndex = 0
		 IndexCol = 0
	 while ArrayIndex < len(s) :
	 if IndexCol % (numRows - 1) == 0 :
		 line = ArrayIndex - (2 * numRows - 2) * int(IndexCol / (numRows - 1))
	 if line < numRows :
		 DecArray[line][IndexCol] = s[ArrayIndex]
	 else :
	 IndexCol += 1
	 ArrayIndex -= 1
	 else:
	 sum = int(IndexCol / (numRows - 1) + 1) * (numRows - 1)
		 line = sum - IndexCol
		 DecArray[line][IndexCol] = s[ArrayIndex]
		 IndexCol += 1
		 ArrayIndex += 1
		 return DecArray
