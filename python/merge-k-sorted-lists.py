# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from Queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        dummy=ListNode(None)
        tail=dummy
        pq=PriorityQueue()
        for l in lists:
            if l: pq.put((l.val, l))
        while not pq.empty():
            t=pq.get()[1]
            tail.next=t
            tail=tail.next
            if t.next: pq.put((t.next.val, t.next))
        return dummy.next

