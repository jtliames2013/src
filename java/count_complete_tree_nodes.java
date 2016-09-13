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
    public int countNodes(TreeNode root) {
        if (root==null) return 0;
        TreeNode n=root;
        int ldepth=0;
        while (n!=null) {
            n=n.left;
            ldepth++;
        }
        
        n=root;
        int rdepth=0;
        while (n!=null) {
            n=n.right;
            rdepth++;
        }
        
        if (ldepth==rdepth) {
            return (1<<ldepth)-1;
        } else {
            return 1+countNodes(root.left)+countNodes(root.right);
        }
    }
}
