class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic=collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dic[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dic: return ""
        i=bisect.bisect(self.dic[key], [timestamp, chr(ord('z')+1)])
        return '' if i==0 else self.dic[key][i-1][1] 


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

2.
class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic=collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dic[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dic: return ""
        l, r=0, len(self.dic[key])
        while l<r:
            mid=(l+r)//2
            if self.dic[key][mid][0]<=timestamp: l=mid+1
            else: r=mid
        return '' if l==0 else self.dic[key][l-1][1]

