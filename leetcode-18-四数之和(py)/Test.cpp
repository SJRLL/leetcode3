����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��
ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺

���в����԰����ظ�����Ԫ�顣

ʾ����

�������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

����Ҫ�����Ԫ�鼯��Ϊ��
[
	[-1, 0, 0, 1],
	[-2, -1, 1, 2],
	[-2, 0, 0, 2]
]

//����˼·��
//ʹ��˫ѭ���̶�����������˫ָ����������������ͨ���Ƚ���target �Ĵ�С���ƶ�ָ�롣������һЩ�Ż�������ֱ�ӿ����룬�ܺ���⣡

class Solution :
	def fourSum(self, nums: List[int], target : int)->List[List[int]] :
	n = len(nums)
if n < 4 : return[]
	nums.sort()
	res = []
	for i in range(n - 3) :
# ��ֹ�ظ� ������� res
	if i > 0 and nums[i] == nums[i - 1]:
	continue
# ��������Сֵ�Ͷ�����target ����
	if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
	break
# ���������ֵ�Ͷ�С��target, ˵��i���������̫С, ������һ��
	if nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target:
	continue
	for j in range(i + 1, n - 2) :
# ��ֹ�ظ� ������� res
	if j - i > 1 and nums[j] == nums[j - 1]:
	continue
# ͬ��
	if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:
	break
# ͬ��
	if nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target:
	continue
# ˫ָ��
		left = j + 1
		right = n - 1
	while left < right:
	tmp = nums[i] + nums[j] + nums[left] + nums[right]
		if tmp == target :
			res.append([nums[i], nums[j], nums[left], nums[right]])
		while left < right and nums[left] == nums[left + 1] :
			left += 1
		while left < right and nums[right] == nums[right - 1] :
			right -= 1
			left += 1
			right -= 1
			elif tmp > target:
		right -= 1
		else:
		left += 1
			return res
