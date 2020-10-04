class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        res=[]
        d=collections.defaultdict(list)
        for (name, time) in zip(keyName, keyTime):
            d[name].append(int(time[:2])*60+int(time[3:]))
            
        for name, time in d.items():
            time.sort()
            i=0
            for j in range(len(time)):
                while time[j]-time[i]>60: i+=1
                if j-i>=2:
                    res.append(name)
                    break
        
        return sorted(res)

