
������Χ[m, n]������ 0 <= m <= n <= 2147483647�����ش˷�Χ���������ֵİ�λ�루���� m, n ���˵㣩��

ʾ�� 1:

���� : [5, 7]
��� : 4
	 ʾ�� 2 :

 ���� : [0, 1]
  ��� : 0

//����˼·����һ���뷨�ǣ�brute force(����ѭ��)����ͷ��β��һ������ˣ����ǲ�֪��������

class Solution :
	def rangeBitwiseAnd(self, m: int, n : int) -> int :
	result = m
for i in range(m + 1, n + 1) :
	result = result&i
	return result
