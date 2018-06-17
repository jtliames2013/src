class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        job=sorted([a, b] for a, b in zip(difficulty, profit))
        res=maxVal=i=0
        for w in sorted(worker):
            while i<len(job) and job[i][0]<=w:
                maxVal=max(maxVal, job[i][1])
                i+=1            
            res+=maxVal
        return res
