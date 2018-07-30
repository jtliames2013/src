# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None or head.next==None: return head
        one, two=head, head.next
        while two:
            one=one.next
            two=two.next.next if two.next else two.next
        return one
