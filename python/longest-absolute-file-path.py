class Solution:
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        res, l=0, 0
        path=[]
        for line in input.splitlines():
            name=line.lstrip('\t')
            n=len(line)-len(name)
            while len(path)>n:
                l-=path[-1]
                path.pop()
            l+=len(name)
            path.append(len(name))
            if '.' in name:
                res=max(res, l+len(path)-1)
        return res
