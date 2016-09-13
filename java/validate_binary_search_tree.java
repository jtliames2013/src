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
    boolean isValidBST(TreeNode root, long lower, long upper) {
        if (root==null) return true;
        if (root.val<=lower || root.val>=upper) return false;
        return isValidBST(root.left, lower, root.val) && isValidBST(root.right, root.val, upper);
    }
    
    public boolean isValidBST(TreeNode root) {
        long lower=Long.MIN_VALUE;
        long upper=Long.MAX_VALUE;
        return isValidBST(root, lower, upper);
    }
}
