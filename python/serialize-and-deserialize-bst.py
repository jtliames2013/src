# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        def dfs(root):
            if not root: return
            vals.append(root.val)
            dfs(root.left)
            dfs(root.right)

        vals=[]
        dfs(root)
        return ','.join(map(str, vals))
    
    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        def dfs(vals, lower, upper):
            if not vals or vals[0]<=lower or vals[0]>=upper: return None
            v=vals.pop(0)
            node=TreeNode(v)
            node.left=dfs(vals, lower, v)
            node.right=dfs(vals, v, upper)
            return node
        
        if not data: return None
        vals=[int(v) for v in data.split(",")]
        return dfs(vals, float("-inf"), float("inf"))

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

