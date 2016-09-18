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
    public int minDepth(TreeNode root) {
        if (root==null) return 0;
        if (root.left==null && root.right==null) return 1;
        int mindepth=Integer.MAX_VALUE;
        if (root.left!=null) {
            mindepth=Math.min(mindepth, minDepth(root.left)+1);
        }
        if (root.right!=null) {
            mindepth=Math.min(mindepth, minDepth(root.right)+1);
        }
        return mindepth;        
    }
}
