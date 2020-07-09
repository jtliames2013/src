class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        if len(arr)%2!=0: return False
        l, r, count=1, k-1, [0]*k
        for a in arr:
            i=a%k
            if i<0: i+=k
            count[i]+=1
        while l<r:
            if count[l]!=count[r]: return False
            l+=1
            r-=1
        return count[0]%2==0

