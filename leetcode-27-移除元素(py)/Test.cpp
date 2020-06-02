给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//解题思路
//1.对输入进来的数组，先进行判断是否为空；为空则返回0
//2.设定循环，对数组中的元素进行扫描：
//如果等于val，就要移除此元素，数组中的元素就少了一个，此时不需要对i进行加一即可找到下一个元素。
//如果不等于，则要手动加1，找到循环的下一个元素！

class Solution :
	def removeElement(self, nums: List[int], val : int) -> int :
if nums == None :
return 0
i = 0
while i < len(nums) :
if nums[i] == val :
nums.remove(nums[i])
continue
else :
i += 1

return len(nums)
