class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        languages=[set(l) for l in languages]
        users=set()
        for u, v in friendships:
            if languages[u-1] & languages[v-1]: continue
            users.add(u-1)
            users.add(v-1)
        
        count=defaultdict(int)
        for u in users:
            for l in languages[u]:
                count[l]+=1
                
        return 0 if not users else len(users)-max(count.values())

