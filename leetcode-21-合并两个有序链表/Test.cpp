将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

//解题思路
//1、建立一个头结点new_head, cur = new_head，cur当返回节点用
//2、遍历l1、l2，如果l1的数值小于l2的数值，则头结点的后面接上l1。反之，接上l2.节点new_head因为后面接了一个节点，
//故而new_head需要后移一个单位。如果l1、l2其中有一个链表遍历完成，则循环结束。
//3、如果l1、l2当中有没有遍历完的，那么接到new_head后的节点上
//4、返回cur.next

# Definition for singly - linked list.
# class ListNode :
#     def __init__(self, x) :
#         self.val = x
#         self.next = None

class Solution :
	def mergeTwoLists(self, l1: ListNode, l2 : ListNode)->ListNode :
# 建立一个头结点
	new_head = ListNode(0)
# 返回的节点
	cur = new_head
# 开始遍历
while l1 and l2 :
# 如果l1的数值比较小
if l1.val < l2.val:
# new_head节点后面接l1
new_head.next = l1
# 因为new_head节点后面接l1，所以new_head节点要后面移动一位
new_head = new_head.next
l1 = l1.next
else:
# l2同理l1
new_head.next = l2
new_head = new_head.next
l2 = l2.next
# 如果l1、l2不等长度，那么在new_head后面接入较长的还剩下的链表头结点
if l1 or l2 :
new_head.next = l1 or l2
# 返回
return cur.next

