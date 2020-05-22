
���������ַ��� s1, s2, s3, ��֤ s3 �Ƿ����� s1 �� s2 ������ɵġ�

ʾ�� 1:

���� : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
��� : true
	 ʾ�� 2 :

 ���� : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
  ��� : false

//˼·һ : ��̬�滮
//�Ե�����
//��̬���� :
//��dp[i][j]��ʾs1��ǰiԪ�غ�s2ǰjԪ���Ƿ񽻴����s3ǰi + jԪ��
//�����ж�̬���� :
//dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
//ע�� : ��Ե�һ��, ��һ��Ҫ��������
//�Զ�����

class Solution :
		def isInterleave(self, s1: str, s2 : str, s3 : str) -> bool :
		 n1 = len(s1)
		 n2 = len(s2)
		 n3 = len(s3)
	 if n1 + n2 != n3 : return False

		 dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]

		 dp[0][0] = True
# ��һ��
	 for j in range(1, n2 + 1) :
		 dp[0][j] = (dp[0][j - 1] and s2[j - 1] == s3[j - 1])

# ��һ��
	 for i in range(1, n1 + 1) :
		 dp[i][0] = (dp[i - 1][0] and s1[i - 1] == s3[i - 1])
# print(dp)

	 for i in range(1, n1 + 1) :
	 for j in range(1, n2 + 1) :
		 dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or(
		 dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
# print(dp)
		 return dp[-1][-1]

