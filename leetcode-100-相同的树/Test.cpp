﻿给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1 :

输入 : 1         1
	 / \        / \
	2   3      2   3

	[1, 2, 3], [1, 2, 3]

输出: true
	示例 2 :

输入 : 1          1
	  /           \
	 2             2

	 [1, 2], [1, null, 2]

 输出: false
 示例 3 :

  输入 : 1          1
	    / \        / \
	   2   1      1   2

	   [1, 2, 1], [1, 1, 2]

   输出: false

//解题思路
//验证相同的树，若当前节点都为空，返回true
//若仅有一个节点为空，说明不相同，返回false
//对比当前节点的值，进入递归，p的左子树和q的左子树对比，p的右子树和q的右子树对比

class Solution {
		 public:
			 bool isSameTree(TreeNode* p, TreeNode* q)
			 {
				 if (!p && !q)    return true;
				 if (!p || !q)    return false; // 说明有且仅有一个为空节点，所以不相同
				 return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			 }
};

