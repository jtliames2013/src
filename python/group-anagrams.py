class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp=collections.defaultdict(list)
        for s in strs: mp[tuple(sorted(s))].append(s)
        
        res=[]
        for group in mp.values(): res.append(group)
        return res
