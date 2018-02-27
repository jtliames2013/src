# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None: return head
        one, two, prev, twoHead=head, head.next, None, head.next
        while one is not None and two is not None:
            oneNext=two.next
            twoNext=oneNext.next if oneNext is not None else None
            one.next=oneNext
            two.next=twoNext
            
            prev=one
            one=oneNext
            two=twoNext
            
        if one is not None: prev=one
        prev.next=twoHead
        
        return head
