假设按照升序排序的数组在预先未知的某个点上进行了旋转。

(例如，数组 [0, 1, 2, 4, 5, 6, 7] 可能变为 [4, 5, 6, 7, 0, 1, 2])。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回  - 1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入 : nums = [4, 5, 6, 7, 0, 1, 2], target = 0
输出 : 4
 示例 2 :

输入 : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
输出 : -1

//解题思路
//左跟中比较，如果左半边有序，判断target在不在左半边，在则j = mid - 1，不在i = mid + 1
//如果左半边不是有序，判断target在不在右半边，在的话i = mid + 1, 不在j = mid - 1

class Solution :
	def search(self, nums: List[int], target : int) -> int :
if not nums :
return -1

i = 0
j = len(nums) - 1
while i <= j :
mid = (i + j)//2
if nums[mid] == target :
return mid
if nums[i] <= nums[mid] :
if nums[i] <= target<nums[mid] :
	j = mid - 1
else :
i = mid + 1
else:
if nums[mid]<target <= nums[j] :
	i = mid + 1
else :
j = mid - 1
return -1


