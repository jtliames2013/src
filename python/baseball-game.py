class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        res=0
        nums=[]
        for op in ops:
            if op=="+":
                n=nums[-1]+nums[-2]
                res+=n
                nums.append(n)
            elif op=="D":
                n=2*nums[-1]
                res+=n
                nums.append(n)
            elif op=="C":
                res-=nums.pop()
            else:
                n=int(op)
                res+=n
                nums.append(n)
        return res
