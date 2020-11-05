class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        i, n=0, len(heights)
        pq=[]
        while i<n-1:
            if heights[i+1]>heights[i]: heappush(pq, heights[i+1]-heights[i])
            if len(pq)>ladders: bricks-=heappop(pq)
            if bricks<0: return i
            i+=1
            
        return i

