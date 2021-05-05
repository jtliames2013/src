class Solution:
    def getMinSwaps(self, num: str, k: int) -> int:
        def next_permutation(num):
            i=len(num)-1
            while i>0:
                if num[i]>num[i-1]: break
                i-=1
            if i==0:
                num.reverse()
                return
            
            k=i-1
            j=len(num)-1
            while j>k:
                if num[j]>num[k]: break
                j-=1
            num[k], num[j]=num[j], num[k]
            num[i:]=reversed(num[i:])
        
            
        num=list(num)
        prev=num.copy()
        for _ in range(k):
            next_permutation(num)
            
        res, i, j, n=0, 0, 0, len(num)
        while i<n:
            j=i
            while prev[i]!=num[j]: j+=1
            
            while j>i:
                num[j], num[j-1]=num[j-1], num
                j-=1
                res+=1
            i+=1
            
        return res

