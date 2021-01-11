# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        curr=start=end=head
        while curr:
            k-=1
            if k==0: start=curr
            if k<0: end=end.next
            curr=curr.next
    
        start.val, end.val=end.val, start.val
        return head

