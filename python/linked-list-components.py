# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        st=set(G)
        res=0
        while head:
            if head.val in st and (head.next is None or head.next.val not in st): res+=1
            head=head.next
            
        return res
