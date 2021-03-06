﻿「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一"), 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。



示例 1 :

输入 : 1
输出 : "1"
	 解释：这是一个基本样例。
	 示例 2 :

 输入 : 4
  输出 : "1211"
	   解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。

//解题思路
//思路同于上一个答案打表，就是用一个a[n] 列表保存这些数据。 题目不难理解，就是a[n - 1] 里有m个连续的1， 那么在a[n]里对应就写作m1。 
//如果不连续了，比如说m个1后出现n个2， 那么对应a[n]里，m1后append n2, 以此类推, 直到遍历完a[n - 1]

class Solution :
		def countAndSay(self, n: int)->str :
		 a = ["0", "1", "11"]
		 for i in range(3, n + 1) :
			 b = []
			 p = 0
			 q = 1
		 for _ in range(len(a[i - 1])) :
		 if  q>len(a[i - 1]) - 1 or a[i - 1][p] != a[i - 1][q]:
		 length = q - p
			 b.append(str(length))
			 b.append(str(a[i - 1][p]))
			 p = q
			 q += 1
			 elif  a[i - 1][p] == a[i - 1][q]:
		 q += 1
			 a.append("".join(b))
			 return a[n]
