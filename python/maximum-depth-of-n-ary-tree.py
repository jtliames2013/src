"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        depth=0
        for child in root.children:
            depth=max(depth, self.maxDepth(child))
        return 1+depth

