1.
class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, zeros, ones, total=0, 0, 0, 0
        for c in s:
            if c=='1': total+=1
        for i in range(len(s)-1):
            if s[i]=='0': zeros+=1
            else: ones+=1
            res=max(res, zeros+total-ones)
            
        return res

2. one pass
class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        res, zeros, ones=float('-inf'), 0, 0
        for i in range(len(s)-1):
            if s[i]=='0': zeros+=1
            else: ones+=1
            res=max(res, zeros-ones)
            
        return res+ones+(s[-1]=='1')

