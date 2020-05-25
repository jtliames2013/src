1.
class Item:
    def __init__(self, word, count):
        self.word=word
        self.count=count
    def __lt__(self, other):
        if self.count==other.count:
            return self.word>other.word
        return self.count<other.count
    
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        res, pq=[], []
        d=collections.Counter(words)
        for key, val in d.items():
            heappush(pq, [Item(key, val), key])
            if len(pq)>k: heappop(pq)
        
        while pq:
            res.append(heappop(pq)[1])
        return res[::-1]

2.
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d=collections.Counter(words)
        return heapq.nsmallest(k, d, lambda w: (-d[w], w))

