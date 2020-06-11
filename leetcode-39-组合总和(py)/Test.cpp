给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1 :

输入 : candidates = [2, 3, 6, 7], target = 7,
所求解集为 :
	  [
		  [7],
		  [2, 2, 3]
	  ]
 示例 2 :

 输入 : candidates = [2, 3, 5], target = 8,
  所求解集为 :
		[
			[2, 2, 2, 2],
			[2, 3, 3],
			[3, 5]
		]

//解题思路
//1、先对列表排序，便于剪枝
//2、从当前位置出发遍历空间集
//3、加入每一个元素
//4、判断是否超过了总和，是则直接返回（因为前面我们已经排过序了）
//5、开始下一轮dfs：因为这道题目要求每一个数字可以重复使用，因此下一轮的start也是当前位置
//6、已经完成一轮dfs，开始返回上一轮做其他选择，先将本轮的选择去掉

class Solution(object) :
		  def combinationSum(self, candidates, target) :
		  """
		  : type candidates : List[int]
		  : type target : int
		  : rtype : List[List[int]]
		  """
		  rst = []
# 先对列表排序，便于剪枝
		  candidates.sort()
		  self.dfs(rst, [], candidates, target, 0)
		  return rst

		  def dfs(self, rst, sub_rst, candidates, target, start) :
# 终止条件：一般就是判断是否找到了一个最优解
	  if sum(sub_rst) == target:
	  rst.append(sub_rst[:])
		  return

# 遍历空间集：从当前位置出发
	  for index in range(start, len(candidates)) :
# 加入每一个元素
		  sub_rst.append(candidates[index])
# 判断是否超过了总和，是则直接返回（因为前面我们已经排过序了）
	  if sum(sub_rst) > target:
	  sub_rst.pop()
		  break
# 开始dfs下一轮：因为这道题目要求每一个数字可以重复使用，因此下一轮的start也是当前位置
# 有的题目要求不能重复使用，那么这里的index应该改为 index + 1
		  self.dfs(rst, sub_rst, candidates, target, index)
# 已经完成一轮dfs，开始返回上一轮做其他选择，先将本轮的选择去掉
		  sub_rst.pop()



