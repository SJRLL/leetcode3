����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

//����˼·
//1.���������п���Ϊ������
//2.�����˸���־λ��ÿ����һ�������ƶ�һλ

class Solution :
	def removeDuplicates(self, nums: List[int]) -> int :
if nums == [] :
return 0
lens = 0
tmp = nums[lens]
	for i in range(len(nums) - 1) :
	if tmp != nums[i + 1] and nums[i] == tmp : # ����
		nums[lens + 1] = nums[i + 1]
		tmp = nums[i + 1]
		lens += 1
		return lens + 1
