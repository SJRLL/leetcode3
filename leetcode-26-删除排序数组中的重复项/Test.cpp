给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

//解题思路
//1.输入数组有可能为空数组
//2.定义了个标志位，每交换一次往后移动一位

class Solution :
	def removeDuplicates(self, nums: List[int]) -> int :
if nums == [] :
return 0
lens = 0
tmp = nums[lens]
	for i in range(len(nums) - 1) :
	if tmp != nums[i + 1] and nums[i] == tmp : # 交换
		nums[lens + 1] = nums[i + 1]
		tmp = nums[i + 1]
		lens += 1
		return lens + 1
