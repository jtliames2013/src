class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        res=[]
        n1, n2, c1, c2=0, 0, 0, 0
        for n in nums:
            if n==n1:
                c1+=1
            elif n==n2:
                c2+=1
            elif c1==0:
                n1=n
                c1+=1
            elif c2==0:
                n2=n
                c2+=1
            else:
                c1-=1
                c2-=1
        
        c1=c2=0
        for n in nums:
            if n==n1: c1+=1
            elif n==n2: c2+=1
                
        if c1>len(nums)//3: res.append(n1)
        if c2>len(nums)//3: res.append(n2)
        return res

