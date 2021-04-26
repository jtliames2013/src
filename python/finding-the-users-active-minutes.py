class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        res=[0]*k
        dic=collections.defaultdict(set)
        for id, time in logs: dic[id].add(time)
        for v in dic.values(): res[len(v)-1]+=1
        return res

