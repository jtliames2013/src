class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        count=[0]*N
        for i,j in trust:
            count[i-1]-=1
            count[j-1]+=1
        for i in range(N):
            if count[i]==N-1: return i+1
        return -1
