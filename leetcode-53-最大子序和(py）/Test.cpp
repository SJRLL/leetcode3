给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 :

输入 : [-2, 1, -3, 4, -1, 2, 1, -5, 4],
输出 : 6
解释 : 连续子数组 [4, -1, 2, 1] 的和最大，为 6。

//解题思路
//对于每一个数，若前面的子数组和为正，则加上前面的子数组作为新的子数组，若为负则保留自身作为新的子数组；每次遍历都与当前最大子数组和做比较，保留较大者。

class Solution :
	def maxSubArray(self, nums: List[int]) -> int :
	maxSum = tempSum = nums[0]
	for num in nums[1:] :
		tempSum = max(num, num + tempSum)
		maxSum = max(maxSum, tempSum)
		return maxSum


