����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ�� :

���� : [1, 1, 2]
��� :
   [
	   [1, 1, 2],
	   [1, 2, 1],
	   [2, 1, 1]
   ]


//����˼·��
//����ĳһ�㣬������ǰ������������ֵ�õ��Ľ�����ظ���
// ��˶���ĳһ�㣬���潻������ֵ�����û�н�������ִ�н�������������ִ��

def permuteUnique(self, nums) :
		 """
		 : type nums : List[int]
		 : rtype : List[List[int]]
		 """
		 result = []
		 count = len(nums)
		 def find(now_index) :
	 if now_index == count :
		 result.append(nums + [])
	 else :
	 temp_set = set()  # ������ǰ��������ֵ
	 for index in range(now_index, count) :
	 if not(nums[now_index], nums[index]) in temp_set : # ��ǰû�н�����
		 temp_set.add((nums[now_index], nums[index]))
		 nums[now_index], nums[index] = nums[index], nums[now_index]
		 find(now_index + 1)
		 nums[now_index], nums[index] = nums[index], nums[now_index]
		 find(0)
		 return result
