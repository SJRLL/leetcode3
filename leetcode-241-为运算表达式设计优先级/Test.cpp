给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 + , -以及 * 。

示例 1 :

输入 : "2-1-1"
输出 : [0, 2]
 解释 :
	((2 - 1) - 1) = 0
	(2 - (1 - 1)) = 2
示例 2 :

 输入 : "2*3-4*5"
  输出 : [-34, -14, -10, -10, 10]
   解释 :
	  (2 * (3 - (4 * 5))) = -34
	  ((2 * 3) - (4 * 5)) = -14
	  ((2 * (3 - 4)) * 5) = -10
	  (2 * ((3 - 4) * 5)) = -10
	  (((2 * 3) - 4) * 5) = 10

//解题思路：按运算符将表达式分成左右两个规模更小的子问题，然后利用分治递归

class Solution {
	 public:
		 vector<int> ans;
		 vector<int> diffWaysToCompute(string input) 
		 {
			 int i, n = input.size();
			 ans = dc(input, 0, n - 1);

			 return ans;
		 }
		 vector<int> dc(string input, int l, int r)
		 {
			 if (l == r) return{ input[l] - '0' };
			 int i = l, j, k, t, cnt;
			 while (i <= r && input[i] >= '0'&&input[i] <= '9') i++;
			 if (i > r)
			 {
				 t = 0;
				 for (i -= 1, cnt = 0; i >= l; i--, cnt++)
				 {
					 t += (input[i] - '0')*pow(10, cnt);
				 }
				 return{ t };
			 }
			 vector<int> ret;
			 for (; i <= r; i++)
			 {
				 while (i <= r && input[i] >= '0'&&input[i] <= '9') i++;
				 if (i>r) break;
				 vector<int> lsum = dc(input, l, i - 1);
				 vector<int> rsum = dc(input, i + 1, r);
				 for (j = 0; j<lsum.size(); j++)
				 {
					 for (k = 0; k<rsum.size(); k++)
					 {
						 switch (input[i])
						 {
						 case '+':ret.push_back(lsum[j] + rsum[k]); break;
						 case '-':ret.push_back(lsum[j] - rsum[k]); break;
						 case '*':ret.push_back(lsum[j] * rsum[k]); break;
						 }
					 }
				 }
			 }

			 return ret;
		 }
};

