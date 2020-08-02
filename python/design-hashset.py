class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size=10000
        self.table=[[] for _ in range(self.size)]

    def add(self, key: int) -> None:
        l=self.table[key%self.size]
        for k in l:
            if k==key: return
        l.append(key)

    def remove(self, key: int) -> None:
        l=self.table[key%self.size]
        for k in l:
            if k==key:
                l.remove(key)
                return

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        l=self.table[key%self.size]
        for k in l:
            if k==key: return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
