class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(i):
            while root[i]!=i: i=root[i]
            return i
        
        count=n
        root=[i for i in range(n)]
        for conn in connections:
            p1=find(conn[0])
            p2=find(conn[1])
            if p1!=p2:
                root[p1]=p2
                count-=1
        return count-1 if len(connections)>=n-1 else -1

