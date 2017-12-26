class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n=len(temperatures)
        res=[0]*n
        stk=[]
        for i in range(n):
            while len(stk)>0 and temperatures[i]>temperatures[stk[-1]]:
                res[stk[-1]]=i-stk[-1]
                stk.pop()
            stk.append(i)
        return res
