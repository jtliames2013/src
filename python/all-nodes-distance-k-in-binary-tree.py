# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        graph=collections.defaultdict(list)
        def dfs(node, parent):
            if not node: return
            if parent:
                graph[parent.val].append(node.val)
                graph[node.val].append(parent.val)
            dfs(node.left, node)
            dfs(node.right, node)
            
        dfs(root, None)
        q=[target.val]
        visited=set(q)
        for i in range(K):
            q=[n for f in q for n in graph[f] if n not in visited]
            visited |= set(q)
        return q
