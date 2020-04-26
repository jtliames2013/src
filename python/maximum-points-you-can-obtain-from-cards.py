class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        res, s, l=float('inf'), 0, len(cardPoints)-k
        for i, v in enumerate(cardPoints):
            s+=v
            if i>=l: s-=cardPoints[i-l]
            if i>=l-1: res=min(res, s)
                
        return sum(cardPoints)-res

