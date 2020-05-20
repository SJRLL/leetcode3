你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入 : [1, 2, 3, 1]
输出 : 4
 解释 : 偷窃 1 号房屋(金额 = 1) ，然后偷窃 3 号房屋(金额 = 3)。
	  偷窃到的最高金额 = 1 + 3 = 4 。
	  示例 2 :

  输入 : [2, 7, 9, 3, 1]
   输出 : 12
	解释 : 偷窃 1 号房屋(金额 = 2), 偷窃 3 号房屋(金额 = 9)，接着偷窃 5 号房屋(金额 = 1)。
		 偷窃到的最高金额 = 2 + 9 + 1 = 12 。



//解题思路
首先建立dp函数，我们假设当小偷偷的最后一家为i家时小偷能偷的最大金额为dp[i]。 
显而易见，对于小偷来说除了第i - 1家不能偷以外，在偷i家之前，其偷过的最后一家可以为[0, i - 2]这个区间中任何一个，
因此我们选择最大的作为其偷i家前所偷到的最大金额，因此为maxValue = max(dp[i]) i = 0, 1, 2, ..., i - 2。 
最后不难计算出，dp[i] = maxValue + nums[i], 这样递推式就出来了。

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






