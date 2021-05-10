class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        pq, res=[], defaultdict(int)
        for q in sorted(queries):
            while intervals and intervals[0][0]<=q:
                l, r=intervals.pop(0)
                if r>=q:
                    heappush(pq, [r-l+1, r])
            while pq and pq[0][1]<q:
                heappop(pq)
            res[q]=pq[0][0] if pq else -1    
        
        return [res[q] for q in queries]

