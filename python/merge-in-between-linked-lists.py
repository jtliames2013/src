# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy=ListNode()
        dummy.next=list1
        
        node_a_prev, node_b=None, None
        prev, curr=dummy, list1
        while curr!=None:
            if curr.val==a: 
                node_a_prev=prev
            if curr.val==b:
                node_b=curr
                break
            prev=curr
            curr=curr.next
        
        curr=list2
        while curr.next!=None:
            curr=curr.next
        
        node_a_prev.next=list2
        curr.next=node_b.next
        
        return dummy.next
        
