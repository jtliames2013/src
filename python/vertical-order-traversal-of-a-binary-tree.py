# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        d=collections.defaultdict(list)
        q=[(root, 0)]
        while q:
            n=len(q)
            curr=collections.defaultdict(list)
            for i in range(n):
                node, x=q.pop(0)
                curr[x].append(node.val)
                if node.left: q.append((node.left, x-1))
                if node.right: q.append((node.right, x+1))
            for k, v in curr.items():
                d[k]+=sorted(v)
        return [d[i] for i in sorted(d)]

