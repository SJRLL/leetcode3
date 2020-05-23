二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1 :

输入 : [1, 3, null, null, 2]

	1
	/
	3
	\
	2

输出:[3, 1, null, null, 2]

   3
   /
   1
   \
   2
示例 2:

 输入 : [3, 1, 4, null, null, 2]

	 3
	 / \
	 1   4
	 /
	 2

 输出:[2, 1, 4, null, null, 3]

	2
	/ \
	1   4
	/
	3

//解题思路：对数组进行排序，让我们从直截了当但却不是最优的解决方案开始。这个解决方案具有线性的时间和空间复杂性。
//我们直到 BST 的中序遍历是升序序列。下面展示了如何计算中序遍历。

public void inorder(TreeNode root, List<Integer> nums) {
	if (root == null) return;
	inorder(root.left, nums);
	nums.add(root.val);
	inorder(root.right, nums);
}

