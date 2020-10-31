class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        maxChar, n="a", len(releaseTimes)
        dic=collections.defaultdict(int)
        for i in range(n):
            dic[keysPressed[i]]=max(dic[keysPressed[i]], releaseTimes[i]-releaseTimes[i-1]) if i>0 else releaseTimes[i]
            
            if dic[keysPressed[i]]>dic[maxChar] or \
               (dic[keysPressed[i]]==dic[maxChar] and keysPressed[i]>maxChar):
                maxChar=keysPressed[i]
            
        return maxChar

