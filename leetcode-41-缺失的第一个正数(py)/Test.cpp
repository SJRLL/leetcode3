给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。


示例 1 :
输入 : [1, 2, 0]
输出 : 3

示例 2 :
输入 : [3, 4, -1, 1]
输出 : 2

示例 3 :
输入 : [7, 8, 9, 11, 12]
输出 : 1

//解题思路
//1、构建字典d，记录输入nums中包含的各数字的出现次数，同时更新nums中的最大值cur_max。
//2、在（1，cur_max + 1）这个范围内搜索出现次数为0的值，将其返回即可

from collections import defaultdict
	 class Solution :
		 def firstMissingPositive(self, nums: List[int]) -> int :
		 d = defaultdict(int)
		 cur_max = 0
	 for i in nums :
	 d[i] += 1
		 cur_max = max(cur_max, i)
	 for j in range(1, cur_max + 2) :
	 if not d[j] :
		 return j

