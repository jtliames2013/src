1.
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(output, s, start):
            if start==len(s):
                res.append(output[:])
                return

            for i in range(start, len(s)):
                curr=s[start:i+1]
                if curr==curr[::-1]:
                    output.append(curr)
                    dfs(output, s, i+1)
                    output.pop()

        res, output=[], []
        dfs(output, s, 0)
        return res

2.
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def dfs(output, s, start):
            if start==len(s):
                res.append(output[:])
                return
            
            for i in range(start, len(s)):
                curr=s[start:i+1]
                if isPalin[start][i]:
                    output.append(curr)
                    dfs(output, s, i+1)
                    output.pop()
                    
        res, output, n=[], [], len(s)
        isPalin=[[False]*n for i in range(n)]
        for l in range(1, n+1):
            for i in range(0, n-l+1):
                j=i+l-1
                if i==j: isPalin[i][j]=True
                elif i+1==j: isPalin[i][j]=(s[i]==s[j])
                else: isPalin[i][j]=(s[i]==s[j] and isPalin[i+1][j-1])
        dfs(output, s, 0)
        return res

