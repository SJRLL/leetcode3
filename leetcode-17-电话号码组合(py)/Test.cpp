����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
ʾ��:

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//����˼·
//��һ�����ֶ�Ӧ���ַ�Ԫ����ڶ������ֶ�Ӧ���ַ�Ԫ��������ϣ��õ�һ�����б����б��е�Ԫ������������ֶ�Ӧ���ַ�Ԫ��������ϣ�
//�ٵõ�һ�����б����ѭ��

class Solution :
	def letterCombinations(self, digits: str)->List[str] :
	dict_d = { '2':'abc', '3' : 'def', '4' : 'ghi', '5' : 'jkl', '6' : 'mno', '7' : 'pqrs', '8' : 'tuv', '9' : 'wxyz' }
if digits == '' :
return[]
ans = ['']
	for num in digits :
	temp = []
		for ele in ans :
		for ala in dict_d[num] :
			temp.append(ele + ala)
			ans = temp
			return ans
