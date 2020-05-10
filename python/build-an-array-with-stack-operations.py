class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res=[]
        j=0
        for i in range(1, n+1):
            if j>=len(target): break
            if i==target[j]:
                res.append("Push")
                j+=1
            else:
                res.append("Push")
                res.append("Pop")
        
        return res

