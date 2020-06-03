实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置(从0开始)。如果不存在，则返回  - 1。

示例 1:

输入 : haystack = "hello", needle = "ll"
输出 : 2
	 示例 2 :

 输入 : haystack = "aaaaa", needle = "bba"
  输出 : -1

//解题思路
//1.对各种极端的情况进行处理（比如，原字符串长度比要寻找的字符串短，空字符串，以及两个字符串本来就相同）
//2.对一般的字符串的操作 （简略代表 A：原字符串 B ： 要寻找的字符串）
//3.对原字符串从头到尾进行循环，如果找到就退出循环
//4.当查找到 A的字符与 B的首字符相同，那就继续探查，如果发现不同，则退出，如果完全相同，则保存下标并退出

class Solution :
    def strStr(self, haystack: str, needle : str) -> int :
	len_hay = len(haystack)
	len_need = len(needle)
    num = -1
#对极端的情况进行判断
	 if len_hay<len_need:
	 return -1
	 if len_need == 0 or len_hay == 0 :
		 return 0
	 if haystack == needle :
		 return 0
#对一般的情况进行判断
	 for i in range(0, len_hay - len_need + 1) :
	 while haystack[i] == needle[0] :
#k充当计数器的作用，判断A是不是完全拟合了B
		 k = 0
	 for j in range(0, len_need) :
	 if haystack[j + i] == needle[j] :
		 k += 1
# continue
# print(k)
	 else :
	 break
#如果K的大小等于B的长度，说明完全拟合，保存下标
	 if k == len_need:
	 num = i
		 break
#当下标变化了之后，说明已经找到相应字符串，直接break
	 if num != -1:
	 break
		 return num
