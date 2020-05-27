class Node:
    def __init__(self, k, v):
        self.key=k
        self.val=v
        self.prev=self.next=None
        
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity=capacity
        self.dic=collections.defaultdict()
        self.head=Node(0, 0)
        self.tail=Node(0, 0)
        self.head.next=self.tail
        self.tail.prev=self.head

    def get(self, key: int) -> int:
        if key not in self.dic: return -1
        n=self.dic[key]
        self.remove(n)
        self.add(n)
        return n.val

    def put(self, key: int, value: int) -> None:
        if key in self.dic: 
            self.remove(self.dic[key])
            self.dic.pop(key)
        n=Node(key, value)
        if len(self.dic)==self.capacity:
            p=self.tail.prev
            self.remove(p)
            self.dic.pop(p.key)
        self.add(n)
        self.dic[key]=n
        
    def add(self, node):
        n=self.head.next
        self.head.next=node
        node.prev=self.head
        node.next=n
        n.prev=node

    def remove(self, node):
        p=node.prev
        n=node.next
        p.next=n
        n.prev=p
        
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

