����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

���� : [1, 2, 3, 1]
��� : 4
 ���� : ͵�� 1 �ŷ���(��� = 1) ��Ȼ��͵�� 3 �ŷ���(��� = 3)��
	  ͵�Ե�����߽�� = 1 + 3 = 4 ��
	  ʾ�� 2 :

  ���� : [2, 7, 9, 3, 1]
   ��� : 12
	���� : ͵�� 1 �ŷ���(��� = 2), ͵�� 3 �ŷ���(��� = 9)������͵�� 5 �ŷ���(��� = 1)��
		 ͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��



//����˼·
���Ƚ���dp���������Ǽ��赱С͵͵�����һ��Ϊi��ʱС͵��͵�������Ϊdp[i]�� 
�Զ��׼�������С͵��˵���˵�i - 1�Ҳ���͵���⣬��͵i��֮ǰ����͵�������һ�ҿ���Ϊ[0, i - 2]����������κ�һ����
�������ѡ��������Ϊ��͵i��ǰ��͵�����������ΪmaxValue = max(dp[i]) i = 0, 1, 2, ..., i - 2�� 
����Ѽ������dp[i] = maxValue + nums[i], ��������ʽ�ͳ����ˡ�

//C++
class Solution {
public:
	int rob(vector<int>& nums) 
	{
		if (nums.empty())
		{
			return 0;
		}
		int len = nums.size();
		if (len == 1)
		{
			return nums[0];
		}
		if (len == 2)
		{
			return max(nums[0], nums[1]);
		}
		vector<int> dp(len);
		dp[0] = nums[0];
		dp[1] = nums[1];
		int maxValue = dp[0];
		int res = dp[1];
		for (int i = 2; i < len; ++i)
		{
			maxValue = max(maxValue, dp[i - 2]);
			dp[i] = maxValue + nums[i];
			res = max(dp[i], res);
		}

		return res;



	}
};

//python
class Solution(object) :
	def rob(self, nums) :
	"""
	: type nums : List[int]
	: rtype : int
	"""
if not nums :
return 0
if len(nums) == 1 :
return nums[0]
f_0 = 0
f_1 = nums[0]
	for i in range(1, len(nums)) :
		f_n = max(f_1, f_0 + nums[i])
		f_0 = f_1
		f_1 = f_n
		return f_n






