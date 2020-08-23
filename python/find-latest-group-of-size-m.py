class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        res, n=-1, len(arr)
        length=[0]*(n+2)
        dic=collections.defaultdict(int)
        for i in range(n):
            j=arr[i]
            l, r=length[j-1], length[j+1]
            length[j]=length[j-l]=length[j+r]=l+r+1
            dic[l]-=1
            dic[r]-=1
            dic[l+r+1]+=1
            if m in dic and dic[m]>0: res=i+1
            
        return res
        
