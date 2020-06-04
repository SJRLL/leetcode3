实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1, 2, 3 → 1, 3, 2
3, 2, 1 → 1, 2, 3
1, 1, 5 → 1, 5, 1

//解题思路
//交换是指：尝试把尽可能低位上的数字和它右边一个更大数字交换
//排序 : 然后把这个交换的数字右侧的数组排成升序

class Solution :
	def nextPermutation(self, nums: List[int])->None :
	"""
	Do not return anything, modify nums in - place instead.
	"""
	n = len(nums)
	i = len(nums) - 2
	minv = nums[n - 1]
	while i >= 0 and nums[i] >= nums[i + 1]:
	i -= 1
		j = n - 1
	while j > i:
	if nums[j] > nums[i]:
	nums[i], nums[j] = nums[j], nums[i]
		while True :
			f = True
			k = i + 1
		while k < n - 1 :
		if nums[k] > nums[k + 1] :
			nums[k], nums[k + 1] = nums[k + 1], nums[k]
			f = False
			k += 1
		if f :
			return
			j -= 1
			nums.sort()

