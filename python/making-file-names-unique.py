class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        res, d=[], {}
        for name in names:
            if name in d:
                i=d[name]
                while True:
                    newname=name+'('+str(i)+')'
                    if newname not in d:
                        break
                    i+=1
                d[name]=i
                d[newname]=1
                res.append(newname)
            else:
                d[name]=1
                res.append(name)
        return res
