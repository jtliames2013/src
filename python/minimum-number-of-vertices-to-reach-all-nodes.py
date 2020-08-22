class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        incomingCnt=[0]*n
        for e in edges:
            incomingCnt[e[1]]+=1
        res=[]
        for i, v in enumerate(incomingCnt):
            if v==0: res.append(i)
        return res

