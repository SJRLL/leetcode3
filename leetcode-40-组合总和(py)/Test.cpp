给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1 :

输入 : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
所求解集为 :
	  [
		  [1, 7],
		  [1, 2, 5],
		  [2, 6],
		  [1, 1, 6]
	  ]
 示例 2:

 输入 : candidates = [2, 5, 2, 1, 2], target = 5,
 所求解集为 :
	   [
		   [1, 2, 2],
		   [5]
	   ]

//解题思路
//与上一题题比较，这里限制candidates中的元素只能使用1次。则下一次搜索要从i + 1开始搜索。
//并且由题知candidates中有重复元素，故先将candidates排序，对后一个元素等于前一个元素且不为首元素的元素，进行减枝。

class Solution :
		  def combinationSum2(self, candidates: List[int], target : int)->List[List[int]] :
#相比39，这里的candidates中的元素只能使用1次
		  size = len(candidates)
	  if size == 0:return[]
		  candidates.sort()
		  path, res, start = [], [], 0

		  def DFS(candidates, start, res, path, target) :
#递归基：target == 0
	  if target == 0:
	  res.append(path[:])
		  return
	  for idx in range(start, size) :
	  if target - candidates[idx]<0 : break#每个元素都不应该大于剩余值
#add the restrain
	  if idx>start and candidates[idx - 1] == candidates[idx] : #prone
		  continue
		  path.append(candidates[idx])
		  target -= candidates[idx]
		  DFS(candidates, idx + 1, res, path, target)
		  target += candidates[idx]
		  path.pop()
		  DFS(candidates, start, res, path, target)
		  return res


