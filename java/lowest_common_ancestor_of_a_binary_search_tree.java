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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root==null || p==null || q==null) return null;
        /*while ((p.val-root.val)*(q.val-root.val)>0) {
            if (p.val-root.val>0) root=root.right;
            else root=root.left;
        }
        return root;*/
        if ((p.val-root.val)*(q.val-root.val)<=0) return root;
        if (p.val>root.val) {
            return lowestCommonAncestor(root.right, p, q);
        } else {
            return lowestCommonAncestor(root.left, p, q);
        }
    }
}
