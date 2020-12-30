class Trie:
    def __init__(self):
        self.root={}
                
    def insert(self, num):
        node=self.root
        for i in range(31, -1, -1):
            b=(num>>i) & 1
            if b not in node:
                node[b]={}
            node=node[b]
        
    def query(self, num):
        if not self.root: return -1
        res, node=0, self.root
        
        for i in range(31, -1, -1):
            b=(num>>i) & 1
            if (b^1) in node:
                node=node[b^1]
                res|=(1<<i)
            else:
                node=node[b]
            
        return res
        
class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        j, n=0, len(nums)
        res=[-1]*len(queries)
        nums.sort()
        queries=sorted(enumerate(queries), key=lambda x:x[1][1])
        trie=Trie()
        for i, (x, m) in queries:
            while j<n and nums[j]<=m:
                trie.insert(nums[j])
                j+=1
            res[i]=trie.query(x)
        
        return res

