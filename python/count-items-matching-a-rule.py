class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        res=0
        dic={'type': 0, 'color': 1, 'name': 2}
        for item in items:
            if item[dic[ruleKey]]==ruleValue:
                res+=1
        return res

