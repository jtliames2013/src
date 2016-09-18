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
    public int maxDepth(TreeNode root) {
        if (root==null) return 0;
        if (root.left==null && root.right==null) return 1;
        int maxdepth=Integer.MIN_VALUE;
        if (root.left!=null) {
            maxdepth=Math.max(maxdepth, maxDepth(root.left)+1);
        }
        if (root.right!=null) {
            maxdepth=Math.max(maxdepth, maxDepth(root.right)+1);
        }
        return maxdepth;        
    }
}
