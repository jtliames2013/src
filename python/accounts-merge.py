class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def find(i):
            while parent[i]!=i: i=parent[i]
            return i
        
        n=len(accounts)
        parent=[0]*n
        for i in range(n): parent[i]=i
        
        email={}
        for i, v in enumerate(accounts):
            for j in range(1, len(v)):
                if v[j] not in email:
                    email[v[j]]=i
                else:
                    p1=find(email[v[j]])
                    p2=find(i)
                    parent[p1]=p2
        
        person=collections.defaultdict(set)
        for i, v in enumerate(accounts):
            for j in range(1, len(v)):
                person[find(i)].add(v[j])
                
        return [ [accounts[k][0]]+sorted(v) for k, v in person.items()]

