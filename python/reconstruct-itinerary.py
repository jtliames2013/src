class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def dfs(city):
            while d[city]:
                dfs(d[city].pop())
            res.append(city)

        d=collections.defaultdict(list)
        for src, dst in sorted(tickets)[::-1]:
            d[src].append(dst)
        
        res=[]
        dfs("JFK")
        return list(reversed(res))
        
