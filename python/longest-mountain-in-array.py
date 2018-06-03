1.
class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res, left, right=0, [0]*len(A), [0]*len(A)        
        for i in range(1, len(A)):
            if A[i]>A[i-1]: left[i]=left[i-1]+1
        for i in range(len(A)-1)[::-1]:
            if A[i]>A[i+1]: right[i]=right[i+1]+1
            if left[i]>0 and right[i]>0: res=max(res, left[i]+right[i]+1)
        return res

2.
class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res, up, down=0, 0, 0 
        for i in range(1, len(A)):
            if A[i]==A[i-1] or (down>0 and A[i]>A[i-1]): up=down=0
            if A[i]>A[i-1]: up+=1
            elif A[i]<A[i-1]: down+=1
            if up>0 and down>0: res=max(res, up+down+1)
        return res
