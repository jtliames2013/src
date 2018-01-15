class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        mp=collections.defaultdict(list)
        for p in paths:
            parts=p.split()
            directory=parts[0]
            for part in parts[1:]:
                file, _, content=part.partition('(')
                mp[content[:-1]].append(directory+'/'+file)
            
        return [ x for x in mp.values() if len(x)>1 ]
