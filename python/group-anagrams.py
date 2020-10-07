class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d=collections.defaultdict(list)
        for s in strs: d[str(sorted(s))].append(s)
            
        res=[]
        for group in d.values(): res.append(group)
        return res
        
