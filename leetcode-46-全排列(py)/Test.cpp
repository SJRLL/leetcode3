����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ�� :

���� : [1, 2, 3]
��� :
   [
	   [1, 2, 3],
	   [1, 3, 2],
	   [2, 1, 3],
	   [2, 3, 1],
	   [3, 1, 2],
	   [3, 2, 1]
   ]

//����˼·
//�ѷ��ʹ��Ľڵ㱣������ ע��ͬһ��������ʽڵ��ʱ�򣬰�����ڵ�ɾ����

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

