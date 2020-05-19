给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。



示例 1:

输入 :
	11110
	11010
	11000
	00000
输出 : 1
 示例 2 :

  输入 :
	 11000
	 11000
	 00100
	 00011
 输出 : 3
  解释 : 每座岛屿只能由水平和 / 或竖直方向上相邻的陆地连接而成。

//解题思路：这类问题是深度优先搜索典型例题。DFS使用递归形式完成，简单明了易于理解。
//注意点是1.要将联通的'1'变成'0'，以便循环不再搜索到，2.注意边界问题


class Solution :
	   def dfs(self, arr, x, y) :

	   arr[x][y] = '0'
   if x - 1 >= 0 and arr[x - 1][y] is '1' :
	   self.dfs(arr, x - 1, y)
   if x + 1 < len(arr) and arr[x + 1][y] is '1' :
	   self.dfs(arr, x + 1, y)

   if y - 1 >= 0 and arr[x][y - 1] is '1' :
	   self.dfs(arr, x, y - 1)
   if y + 1 < len(arr[0]) and arr[x][y + 1] is '1' :
	   self.dfs(arr, x, y + 1)

	   return None

	   def numIslands(self, grid: List[List[str]]) -> int :

	   islandsNum = 0
   for i in range(len(grid)) :
   for j in range(len(grid[0])) :
   if grid[i][j] is '1' :
	   islandsNum += 1
	   self.dfs(grid, i, j)
return islandsNum




