# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        curr=dummy
        prefix=0
        d=collections.defaultdict()
        while curr:
            prefix+=curr.val
            if prefix in d:                
                n=d.get(prefix).next
                p=prefix+n.val
                while n!=curr:
                    del d[p]                    
                    n=n.next
                    p+=n.val
                d[prefix].next=curr.next
            else:
                d[prefix]=curr
            curr=curr.next
        
        return dummy.next
