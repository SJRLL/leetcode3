给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例 :

输入 : [2, 3, 1, 1, 4]
输出 : 2
 解释 : 跳到最后一个位置的最小跳跃数是 2。
	  从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

//解题思路
// 因为跳到目前能够跳到的最远距离的地方，不一定能使之后的第二条到达最远距离
//因此，设计估值函数为“第二跳”能够到达的最远距离
//为此，需要
//1.遍历当前第一跳能够到达的所有位置
//2.计算跳到该位置后能到达的最远距离作为该位置的估值函数
//3.选择估值函数的值最大的位置作为下一跳的目标
//当最远距离达到或超过目标位置时即可返回True
//当最远距离只有当前位置时，表示无法再往前跳，因此返回False

class Solution(object) :
		 def jump(self, nums) :
		 """
		 : type nums : List[int]
		 : rtype : int
		 """
		 top = len(nums) - 1
	 if top == 0 : #排除0跳的特殊情况
		 return 0
		 maxdis = nums[0]
		 count = 0
		 pos = 0#记录当前位置
	 while True:
	 if maxdis >= top :
		 return count + 1
		 pos1 = pos#创建pos的副本，因为在接下来的操作中会涉及到pos的改变
	 for i in range(1, nums[pos] + 1) :#在目前能够到达的范围内，寻找能使“之后第二跳”到达最远距离的位置
	 if nums[pos + i] + pos + i>maxdis:
	 maxdis = nums[pos + i] + i + pos#nums[pos + i] + i + pos即为第二跳能够到达的最远距离
		 pos1 = pos + i
		 pos = pos1
		 count += 1
	 if pos >= maxdis:#当能达到的最远距离为当前位置时，表示无法再前进
		 return False

