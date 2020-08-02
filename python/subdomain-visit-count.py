class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        d=collections.defaultdict(int)
        for s in cpdomains:
            num, domain=s.split()
            d[domain]+=int(num)
            for i in range(len(domain)):
                if domain[i]=='.': d[domain[i+1:]]+=int(num)
        return ['{1} {0}'.format(k, v) for k, v in d.items()]

