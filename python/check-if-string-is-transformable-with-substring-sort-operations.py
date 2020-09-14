class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        idx=[[] for i in range(10)]
        pos=[0]*10
        for i, v in enumerate(s):
            idx[ord(v)-ord('0')].append(i)
        
        for i, v in enumerate(t):
            c=ord(v)-ord('0')
            if pos[c]>=len(idx[c]): return False
            for j in range(c):
                if pos[j]<len(idx[j]) and idx[j][pos[j]]<idx[c][pos[c]]: return False
            pos[c]+=1
            
        return True
