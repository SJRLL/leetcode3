编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例 :

现有矩阵 matrix 如下：

[
	[1, 4, 7, 11, 15],
	[2, 5, 8, 12, 19],
	[3, 6, 9, 16, 22],
	[10, 13, 14, 17, 24],
	[18, 21, 23, 26, 30]
]

//解题思路：
每次从右上角开始查找：
若右上角数大于target，由于有序特性，则该列数都大于target，所以排除该列所有数；
如果右上角数小于target，由于有序特性，则改行数都小于target，所以排除该行所有数；
如果相等，则找到并停止查找。

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		//边界值
		if (matrix.size() == 0 || matrix[0].size() == 0) 
		{
			return false;
		}
		int row = matrix.size(), col = matrix[0].size();
		int i = 0, j = col - 1;
		while (i < row && j >= 0) 
		{
			if (matrix[i][j] == target) 
			{
				return true;
			}
			else if (matrix[i][j] < target) 
			{
				++i;
			}
			else if (matrix[i][j] > target) 
			{
				--j;
			}
		}
		return false;
	}
};

