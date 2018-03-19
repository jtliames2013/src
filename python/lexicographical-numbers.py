class Solution:
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def dfs(res, n, curr):
            if curr>n: return
            res.append(curr)
            for i in range(10):
                dfs(res, n, curr*10+i)

        res=[]
        for i in range(1, 10):
            dfs(res, n, i)
        return res
