class Solution:
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        def dfs(start):            
            if start==len(S): return len(res)>2
            for i in range(start, len(S)):
                if i-start+1>maxLen: break
                if S[start]=='0' and i>start: break
                num=int(S[start:i+1])
                if num>2**31-1: break
                if len(res)<2 or num==sum(res[-2:]):
                    res.append(num)
                    if dfs(i+1): return True
                    res.pop()
                elif num>sum(res[-2:]):
                    break
                    
            return False
                
        res, maxLen=[], 10
        dfs(0)
        return res
