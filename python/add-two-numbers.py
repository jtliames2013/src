# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy=tail=ListNode(0)
        carry=False
        while l1 is not None or l2 is not None:
            num=0
            if l1 is not None:
                num+=l1.val
                l1=l1.next
            if l2 is not None:
                num+=l2.val
                l2=l2.next
            if carry:
                num+=1
                carry=False
            if num>9:
                num%=10
                carry=True
            tail.next=ListNode(num)
            tail=tail.next
        if carry:
            tail.next=ListNode(1)
        return dummy.next
