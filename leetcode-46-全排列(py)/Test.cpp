给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例 :

输入 : [1, 2, 3]
输出 :
   [
	   [1, 2, 3],
	   [1, 3, 2],
	   [2, 1, 3],
	   [2, 3, 1],
	   [3, 1, 2],
	   [3, 2, 1]
   ]

//解题思路
//把访问过的节点保存起来 注意同一层更换访问节点的时候，把这个节点删除掉

class Solution :
		 def permute(self, nums: List[int])->List[List[int]] :
		 N = len(nums)
		 visited = set()

		 def bt(cnt, path, res) :
	 if cnt == 0 :
		 res.append(path)
		 return
	 for s in range(N) :
	 if s not in visited :
	 visited.add(s)
		 bt(cnt - 1, path + [nums[s]], res)
		 visited.remove(s)

		 res = []
		 bt(N, [], res)
		 return res

