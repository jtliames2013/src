class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res=[]
        self.dfs(res, "", n, n)
        return res
        
    def dfs(self, res, output, left, right):        
        if left==0 and right==0:
            res.append(output)
            return
        if left>0:
            self.dfs(res, output+"(", left-1, right)
        if left<right:
            self.dfs(res, output+")", left, right-1)
    
