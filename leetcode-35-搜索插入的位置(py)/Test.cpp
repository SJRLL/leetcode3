给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入 : [1, 3, 5, 6], 5
输出 : 2
 示例 2 :

  输入 : [1, 3, 5, 6], 2
   输出 : 1
		示例 3 :

	输入 : [1, 3, 5, 6], 7
	 输出 : 4
		  示例 4 :

	  输入 : [1, 3, 5, 6], 0
	   输出 : 0

//解题思路
//1.对极端情况进行判断，当target比数组中的任意一个数都小或都大；
//2.对target是否在数组中进行判断
//3.当在数组中的时候，找到其下标位置（默认数组为无重复数组）
//4.当没有在数组中的时候，
//找到第一个数字比target大的元素，这个元素的下标位置就是target插入数组的位置。

class Solution :
		 def searchInsert(self, nums: List[int], target : int) -> int :
		 result = None
#对极端情况进行判断
	 while target > nums[len(nums) - 1]:
	 result = len(nums)
		 break
	 while target < nums[0] :
		 result = 0
		 break
#当target在数组中时
	 if target in nums :
	 for i in range(0, len(nums)) :
	 if nums[i] == target :
		 result = i
		 break
#当target不在数组中时：
	 else :
	 for j in range(0, len(nums)) :
	 if target < nums[j] :
		 result = j
		 break
		 return result

