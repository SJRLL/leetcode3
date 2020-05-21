插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。


示例 1：

输入 : 4->2->1->3
 输出 : 1->2->3->4
	  示例 2：

  输入 : -1->5->3->4->0
   输出 : -1->0->3->4->5

//解题思路：将下一个待排序的值和上一次结果比较，判断开始位置

		# Definition for singly - linked list.
		# class ListNode(object) :
		#     def __init__(self, x) :
		#         self.val = x
		#         self.next = None

		class Solution(object) :
		def insertionSortList(self, head) :
		"""
		: type head : ListNode
		: rtype : ListNode
		"""
		if not head :
		return head
		node = head.next
		sortList = ListNode(0)
		sortList.next = head
		sortNode = sortList.next
		sortNode.next = None
		prevNode = sortList
		lastNode = head
		while node:
		#print(sortList.next)
		nextNode = node.next
		if prevNode.val <= node.val:
		sortNode = prevNode.next
		else:
		prevNode = sortList
		sortNode = sortList.next
		while sortNode :
		if node.val <= sortNode.val :
		node.next = sortNode
		prevNode.next = node
		break
		else :
		sortNode = sortNode.next
		prevNode = prevNode.next
		if sortNode == None :
		prevNode.next = node
		node.next = None
		node = nextNode
		return sortList.next

