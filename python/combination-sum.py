class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res=[]
        output=[]
        self.getSum(res, output, candidates, target, 0)
        return res
    
    def getSum(self, res, output, candidates, target, start):
        if target==0:
            res.append(list(output))
            return
        
        for i in range(start, len(candidates)):
            if target-candidates[i]>=0:
                output.append(candidates[i])                
                self.getSum(res, output, candidates, target-candidates[i], i)
                output.pop()                
