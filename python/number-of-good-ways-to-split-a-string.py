class Solution:
    def numSplits(self, s: str) -> int:
        res=0
        pc, qc=collections.defaultdict(int), collections.Counter(s)
        for c in s:
            pc[c]+=1
            qc[c]-=1
            if qc[c]==0: qc.pop(c)
            if len(pc)==len(qc): res+=1

        return res
