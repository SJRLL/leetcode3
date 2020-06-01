给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。



示例：

给你这个链表：1->2->3->4->5

当 k  = 2 时，应当返回: 2->1->4->3->5

当 k  = 3 时，应当返回 : 3->2->1->4->5


//解题思路
//如果需要翻转，依次往头节点后方插入，完成翻转，更新头节点。

class ListNode :
	def __init__(self, x) :
	self.val = x
	self.next = None


class Solution :
	def reverseKGroup(self, head: ListNode, k : int)->ListNode :
	dummy = ListNode(0)
	dummy.next = head
	tmp, begin = head, head
	p = dummy
	cnt = k
while True:
tail = begin
cnt = k
while cnt and tmp :
tmp = tmp.next
cnt -= 1
if cnt == 0 :
while begin != tmp :
p.next, begin.next, begin = begin, p.next, begin.next
p = tail
else:
p.next = tail
break
return dummy.next

