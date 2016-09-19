/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    class Element {
        int withSelf;
        int withoutSelf;
        Element(int w, int o) {
            withSelf=w;
            withoutSelf=o;
        }
    }
    
    Element dfs(TreeNode root) {
        if (root==null) return new Element(0, 0);
        if (root.left==null && root.right==null) {
            return new Element(root.val, 0);
        }
        
        Element left=dfs(root.left);
        Element right=dfs(root.right);
        
        return new Element(root.val+left.withoutSelf+right.withoutSelf, Math.max(left.withSelf, left.withoutSelf)+Math.max(right.withSelf, right.withoutSelf));
    }
    
    public int rob(TreeNode root) {
        Element e=dfs(root);
        return Math.max(e.withSelf, e.withoutSelf);
    }
}
