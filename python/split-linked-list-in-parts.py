# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        curr, n = root, 0
        while curr:
            n+=1
            curr=curr.next
        div, mod = n/k, n%k
        res=[None]*k
        curr=root
        for i in range(k):
            len=div
            if i<mod:
                len+=1
            if len==0:
                break
            res[i]=curr
            for j in range(len):
                prev=curr
                curr=curr.next
            prev.next=None
        return res
