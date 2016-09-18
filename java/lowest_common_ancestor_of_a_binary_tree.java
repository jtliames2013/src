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
        if (root==p || root==q) return root;
        TreeNode left=lowestCommonAncestor(root.left, p, q);
        TreeNode right=lowestCommonAncestor(root.right, p, q);
        if (left!=null && right!=null) return root;
        else if (left!=null) return left;
        else if (right!=null) return right;
        else return null;
    }
}

2.
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
    boolean getPath(TreeNode root, TreeNode n, List<TreeNode> path) {
        if (root==null || n==null) return false;
        path.add(root);
        
        if (root==n) return true;
        
        if (root.left!=null) {
            if (getPath(root.left, n, path)==true) return true;
        }
        
        if (root.right!=null) {
            if (getPath(root.right, n, path)==true) return true;
        }
        path.remove(path.size()-1);
        return false;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root==null || p==null || q==null) return null;
        List<TreeNode> path1=new ArrayList<>();
        List<TreeNode> path2=new ArrayList<>();
        getPath(root, p, path1);
        getPath(root, q, path2);
        
        int prev=0;
        for (int i=0; i<path1.size() && i<path2.size(); i++) {
            if (path1.get(i)!=path2.get(i)) break;
            prev=i;
        }
        return path1.get(prev);
    }
}
