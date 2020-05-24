class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        res=[]
        d={i: set(v) for i, v in enumerate(favoriteCompanies)}
        for i in range(len(favoriteCompanies)):
            subset=False
            for j in range(len(favoriteCompanies)):
                if i==j: continue
                    
                if not d[i]-d[j]:
                    subset=True
                    break
            
            if not subset: res.append(i)
        
        return res

