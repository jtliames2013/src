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
    TreeNode flatten(TreeNode root, TreeNode parent) {
        if (root==null) return null;
        if (parent!=null) {
            parent.left=null;
            parent.right=root;
        }
        TreeNode last=root, right=root.right;
        
        if (root.left!=null) {
            last=flatten(root.left, root);    
        }
        
        if (right!=null) {
            last=flatten(right, last);
        }
        return last;
    }
    
    public void flatten(TreeNode root) {
        flatten(root, null);
    }
}
