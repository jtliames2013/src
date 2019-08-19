1. BFS
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        maxSum, maxLevel, level=0, 0, 0
        if (not root): return maxLevel
        q=collections.deque()
        q.append(root)
        level+=1
        while q:
            s=0
            for i in range(len(q)):
                n=q.popleft()
                s+=n.val
                if (n.left): q.append(n.left)
                if (n.right): q.append(n.right)
            if s>maxSum:
                maxSum, maxLevel=s, level
            level+=1
        
        return maxLevel
        

2. DFS
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, s: List, level: int):
            if not root: return
            if len(s)==level: s.append(0)
            s[level]+=root.val
            dfs(root.left, s, level+1)
            dfs(root.right, s, level+1)

        s=[]
        dfs(root, s, 0)
        return s.index(max(s))+1
    

