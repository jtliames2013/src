# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        dummy=tail=ListNode()
        pq=PriorityQueue()
        for l in lists:
            if l: pq.put((l.val, l))
        while not pq.empty():
            t=pq.get()[1]
            tail.next=t
            tail=t
            if t.next: pq.put((t.next.val, t.next))
        return dummy.next        


2. heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy=tail=ListNode()
        # in case of tie-break of val comparison, compare index instead of ListNode
        pq=[(l.val, i, l) for i, l in enumerate(lists) if l]
        heapify(pq)
        while pq:
            v, i, l=pq[0]
            heappop(pq)
            tail.next=l
            tail=l
            if l.next: heappush(pq, (l.next.val, i, l.next))
        return dummy.next

3.
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy=tail=ListNode()
        # in case of tie-break of val comparison, compare index instead of ListNode
        pq=[]
        for i, l in enumerate(lists):
            if l:
                heappush(pq, (l.val, i, l))
        while pq:
            v, i, l=pq[0]
            heappop(pq)
            tail.next=l
            tail=l
            if l.next: heappush(pq, (l.next.val, i, l.next))
        return dummy.next

