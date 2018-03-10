class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data, self.mp=[], {}

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.mp: return False
        self.mp[val]=len(self.data)
        self.data.append(val)
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.mp: return False
        if val != self.data[-1]:
            idx=self.mp[val]
            self.mp[self.data[-1]]=idx
            self.data[idx]=self.data[-1]
        self.data.pop()
        self.mp.pop(val)
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.data[random.randint(0, len(self.data)-1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
