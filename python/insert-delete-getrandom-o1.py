class RandomizedSet:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data, self.dic=[], {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.dic: return False
        self.dic[val]=len(self.data)
        self.data.append(val)
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.dic: return False
        if val!=self.data[-1]:
            idx=self.dic[val]
            self.dic[self.data[-1]]=idx
            self.data[idx]=self.data[-1]
        self.data.pop()
        self.dic.pop(val, None)
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return self.data[random.randint(0, len(self.data)-1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

