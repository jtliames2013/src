1.
class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        n=len(dominoes)
        res, dist=list(dominoes), [sys.maxsize]*n
        if dominoes[0]!='.': dist[0]=0
        for i in range(1,n):
            if dominoes[i]!='.': dist[i]=0
            else:
                if res[i-1]=='R':
                    res[i]=res[i-1]
                    dist[i]=dist[i-1]+1
        for i in range(n-1)[::-1]:
            if res[i+1]=='L':
                if dist[i]>dist[i+1]+1:
                    dist[i]=dist[i+1]+1
                    res[i]=res[i+1]
                elif dist[i]==dist[i+1]+1:
                    res[i]='.'
        return ''.join(res)


2.
class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        dominoes='L'+dominoes+'R'
        res=[]
        l=0
        for r in range(1, len(dominoes)):
            if dominoes[r]=='.': continue
            length=r-l-1
            if l>0: res.append(dominoes[l])
            if dominoes[l]==dominoes[r]: res.append(dominoes[l]*length)
            elif dominoes[l]=='L' and dominoes[r]=='R': res.append('.'*length)
            else: res.append('R'*(length//2) + '.'*(length%2) + 'L'*(length//2))
            l=r
                
        return ''.join(res)
