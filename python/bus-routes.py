class Solution:
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        d=collections.defaultdict(set)
        for i in range(len(routes)):
            for stop in routes[i]: d[stop].add(i)
                
        visited=set([S])
        q=[S]
        level=0
        
        while q:
            nq=[]
            for f in q:            
                if f==T: return level
                for route in d[f]:
                    for stop in routes[route]:
                        if stop not in visited:
                            nq.append(stop)
                            visited.add(stop)
                    routes[route]=[]
            q=nq
            level+=1
            
        return -1
