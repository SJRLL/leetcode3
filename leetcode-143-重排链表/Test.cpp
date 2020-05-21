给定一个单链表 L：L0→L1→…→Ln - 1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln - 1→L2→Ln - 2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1 :

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2 :

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

//思路：
//1.找到中点；
//2.分为两个链表；
//3.第二个链表反转；
//4.奇偶合并链表，merge


class Solution(object) :
	def reorderList(self, head) :
	"""
	: type head : ListNode
	: rtype : None Do not return anything, modify head in - place instead.
	"""
if head == None or head.next == None :
return None
mid = self.findMiddle(head)
tail = self.reverse(mid.next)
mid.next = None
return self.merge(head, tail)


def findMiddle(self, head) :
slow = head
fast = head.next
while fast != None and fast.next != None :
slow = slow.next
fast = fast.next.next
return slow

def reverse(self, head) :
prove = None
while head != None :
temp = head.next
head.next = prove
prove = head
head = temp
return prove

def merge(self, head1, head2) :
dummy = ListNode(0)
index = 0
tail = dummy
while head1 and head2 :
if index % 2 == 0 :
tail.next = head1
head1 = head1.next
else :
tail.next = head2
head2 = head2.next
index += 1
//#  这一步很容易忘掉
tail = tail.next
if head1 != None:
tail.next = head1
if head2 != None :
tail.next = head2
return dummy.next

