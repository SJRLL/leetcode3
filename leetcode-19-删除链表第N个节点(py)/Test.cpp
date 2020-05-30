给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表 : 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

//解题思路
//建立一个哨兵，并用head.c记录一下头节点，然后头节点先走n步，如果此时走到了空节点，
//直接返回headc.next, 否则, headc和head同时往后移动，直到head.next为空，说明head.next已经走到了尾节点，
//那headc的现在的位置就是要删除节点的前驱节点，把它的后继绕过要删除的节点指向要删除的节点的后一个节点

# Definition for singly - linked list.
# class ListNode :
# def __init__(self, val = 0, next = None) :
# self.val = val
# self.next = next
class Solution :
	def removeNthFromEnd(self, head: ListNode, n : int)->ListNode :
	if not head : return
	dum = ListNode(0)
	headc = head
	dum.next = head
	for i in range(n) :
	head = head.next
	if not head : return headc.next
	while head.next :
	headc = headc.next
	head = head.next
	headc.next = headc.next.next
	return dum.next

