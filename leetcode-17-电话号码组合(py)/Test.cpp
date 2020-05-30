给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//解题思路
//第一个数字对应的字符元素与第二个数字对应的字符元素排列组合，得到一个新列表；新列表中的元素与第三个数字对应的字符元素排列组合，
//再得到一个新列表；如此循环

class Solution :
	def letterCombinations(self, digits: str)->List[str] :
	dict_d = { '2':'abc', '3' : 'def', '4' : 'ghi', '5' : 'jkl', '6' : 'mno', '7' : 'pqrs', '8' : 'tuv', '9' : 'wxyz' }
if digits == '' :
return[]
ans = ['']
	for num in digits :
	temp = []
		for ele in ans :
		for ala in dict_d[num] :
			temp.append(ele + ala)
			ans = temp
			return ans
