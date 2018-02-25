class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        nums=[0]*(len(num1)+len(num2))
        for i in reversed(range(len(num1))):
            for j in reversed(range(len(num2))):
                val=(ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
                p1, p2=i+j, i+j+1
                val+=nums[p2]
                nums[p1]+=int(val/10)
                nums[p2]=val%10
                
        k=0
        while k<len(nums)-1 and nums[k]==0: k+=1
        return ''.join(map(str, nums[k:]))
