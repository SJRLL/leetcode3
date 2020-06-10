编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1 - 9 在每一行只能出现一次。
数字 1 - 9 在每一列只能出现一次。
数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

//解题思路
//简单回溯算法，使用行、列、宫进行约束剪枝，每次根据三种约束进行迭代，如果填完并最后一格有可填值则完成

class Solution :
	def solveSudoku(self, board: List[List[str]])->None :
	x_constraint = [[0 for _ in range(9)] for _ in range(9)]
	y_constraint = [[0 for _ in range(9)] for _ in range(9)]
	z_constraint = [[0 for _ in range(9)] for _ in range(9)]
	for i, row in enumerate(board) :
	for j, item in enumerate(row) :
	if item != '.' :
		x_constraint[i][int(item) - 1] = 1
		y_constraint[j][int(item) - 1] = 1
		z_constraint[i // 3 * 3 + j // 3][int(item) - 1] = 1
		def solve(x, y):
#print('Try to solve: ', x, y)
	constraint = [a + b + c for a, b, c in zip(x_constraint[x], y_constraint[y], z_constraint[x // 3 * 3 + y // 3])]
#print('Constraint: ', constraint)
	for i, num in enumerate(constraint) :
	if num == 0 :
		board[x][y] = str(i + 1)
		addConstraint(x, y, i + 1)
	if not findNext(x, y) :
		return True
		elif solve(*findNext(x, y)) :
		return True
	else:
	board[x][y] = '.'
		resetConstraint(x, y, i + 1)
		return False
		def addConstraint(x, y, num) :
		x_constraint[x][int(num - 1)] = 1
		y_constraint[y][int(num - 1)] = 1
		z_constraint[x // 3 * 3 + y // 3][int(num - 1)] = 1
		def resetConstraint(x, y, num):
	x_constraint[x][int(num - 1)] = 0
		y_constraint[y][int(num - 1)] = 0
		z_constraint[x // 3 * 3 + y // 3][int(num - 1)] = 0
		def nextPosition(x, y):
	return (x * 9 + y + 1) // 9, (x * 9 + y + 1) % 9
		def findNext(x, y) :
	while board[x][y] != '.' :
		x, y = nextPosition(x, y)
	if x == 9 :
		return False
# print('Next grid: ', x, y)
		return x, y
		solve(*(findNext(0, 0)))
