# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res=0
        
    def countPairs(self, root: TreeNode, distance: int) -> int:
        def dfs(root):
            if not root: return {}
            if not root.left and not root.right: return {0: 1}
            l=dfs(root.left)
            r=dfs(root.right)
            d=collections.defaultdict(int)
            for k1, v1 in l.items():
                for k2, v2 in r.items():
                    if k1+k2+2<=distance:
                        self.res+=v1*v2
            for k, v in l.items(): 
                if k+1<distance: d[k+1]=v
            for k, v in r.items(): 
                if k+1<distance: d[k+1]+=v
            return d
        
        dfs(root)
        return self.res
