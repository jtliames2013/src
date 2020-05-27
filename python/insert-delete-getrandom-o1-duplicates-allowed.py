class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data, self.dic=[], collections.defaultdict(set)

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        res=False
        if val not in self.dic: res=True
        self.dic[val].add(len(self.data))
        self.data.append(val)
        return res

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.dic: return False
        idx=len(self.data)-1
        if val!=self.data[-1]:
            idx=next(iter(self.dic[val]))
            self.dic[self.data[-1]].remove(len(self.data)-1)
            self.dic[self.data[-1]].add(idx)
            self.data[idx]=self.data[-1]
        self.dic[val].remove(idx)
        self.data.pop()
        if len(self.dic[val])==0: self.dic.pop(val, None)
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.data)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

