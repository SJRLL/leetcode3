给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入 : nums = [5, 7, 7, 8, 8, 10], target = 8
输出 : [3, 4]
 示例 2 :

输入 : nums = [5, 7, 7, 8, 8, 10], target = 6
输出 : [-1, -1]

//解题思路
//利用python内置的bisect模块的左查找、右查找，稍加判断即可。

class Solution :
	def searchRange(self, nums: List[int], target : int)->List[int] :
	tmp = bisect.bisect(nums, target)
	indexR = tmp - 1 if tmp>0 and nums[tmp - 1] == target else - 1

	tmp = bisect.bisect_left(nums, target)
	indexL = tmp if tmp<len(nums) and nums[tmp] == target else - 1

	return[indexL, indexR]

