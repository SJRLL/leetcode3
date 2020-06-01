//解题思路
//按照归并排序的思路，不断遍历两个数组，取最小的值追加到链表中，在某个链表结束遍历之后，
//将另一个链表剩余的值拼接到新链表中。

# Definition for singly - linked list.
# class ListNode(object) :
#     def __init__(self, x) :
#         self.val = x
#         self.next = None

class Solution(object) :
	def mergeTwoLists(self, l1, l2) :
	"""
	: type l1 : ListNode
	: type l2 : ListNode
	: rtype : ListNode
	"""
	head = ListNode(None)
	l3 = head
while l1 and l2 :
if l1.val > l2.val:
node = ListNode(l2.val)
l2 = l2.next
else :
node = ListNode(l1.val)
l1 = l1.next
l3.next = node
l3 = l3.next
if l1 :
l3.next = l1
else:
l3.next = l2
return head.next

