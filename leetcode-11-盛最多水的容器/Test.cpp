给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0)。
出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。


//解题思路：
//1、盛水量 = 两个值里较小的值 x 两个值之间的距离；
//2、从队首找一个值，队尾找一个值，算出当前盛水量；
//3、比较当前的首尾值，如果队尾的小那么就向前更新队尾值，如果队首的小那么就向后更新队首值；
//4、直到队首和队尾的位置相遇。

class Solution(object) :
	def maxArea(self, height) :
	"""
	: type height : List[int]
	: rtype : int
	"""
	ans = 0
	i = 0     #初始化队首位置
	j = len(height) - 1      #初始化队尾位置
for i in range(j) : #更新队首位置
for j in range(j, i, -1) : #更新队尾位置
a = ans
ans = min(height[i], height[j]) * (j - i)
ans = max(a, ans)         #计算更新最大的盛水量
if height[i] < height[j]:
break
return ans

