1. DFS
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return None
        d={}
        return self.dfs(node, d)
    
    def dfs(self, node, d):
        n=Node(node.val)
        d[node]=n
        for neighbor in node.neighbors:
            if neighbor not in d:
                self.dfs(neighbor, d)
            n.neighbors.append(d[neighbor])
        
        return n

2. BFS
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return None
        newNode=Node(node.val)
        q=collections.deque([node])
        d={node: newNode}
        while q:
            f=q.popleft()
            for neighbor in f.neighbors:
                if neighbor not in d:
                    n=Node(neighbor.val)
                    d[neighbor]=n
                    q.append(neighbor)
                d[f].neighbors.append(d[neighbor])

        return newNode

