class Solution:
    def advantageCount(self, A: 'List[int]', B: 'List[int]') -> 'List[int]':
        d=collections.defaultdict(list)
        A=sorted(A)
        for i in sorted(B)[::-1]:
            if i<A[-1]:
                d[i].append(A.pop())
        return [ (d[i] or A).pop() for i in B]

