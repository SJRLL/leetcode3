ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1, 2, 3 �� 1, 3, 2
3, 2, 1 �� 1, 2, 3
1, 1, 5 �� 1, 5, 1

//����˼·
//������ָ�����԰Ѿ����ܵ�λ�ϵ����ֺ����ұ�һ���������ֽ���
//���� : Ȼ�����������������Ҳ�������ų�����

class Solution :
	def nextPermutation(self, nums: List[int])->None :
	"""
	Do not return anything, modify nums in - place instead.
	"""
	n = len(nums)
	i = len(nums) - 2
	minv = nums[n - 1]
	while i >= 0 and nums[i] >= nums[i + 1]:
	i -= 1
		j = n - 1
	while j > i:
	if nums[j] > nums[i]:
	nums[i], nums[j] = nums[j], nums[i]
		while True :
			f = True
			k = i + 1
		while k < n - 1 :
		if nums[k] > nums[k + 1] :
			nums[k], nums[k + 1] = nums[k + 1], nums[k]
			f = False
			k += 1
		if f :
			return
			j -= 1
			nums.sort()

