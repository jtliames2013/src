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
    public void recoverTree(TreeNode root) {
        TreeNode first=null, second=null;
        Stack<TreeNode> stack=new Stack<>();
        TreeNode n=root;
        while (n!=null) {
            stack.push(n);
            n=n.left;
        }
        
        TreeNode prev=null;
        while (!stack.empty()) {
            TreeNode t=stack.pop();
            if (prev!=null) {
                if (prev.val>t.val) {
                    if (first==null) {
                        first=prev;
                        second=t;
                    } else {
                        second=t;
                    }
                }
            }
            
            prev=t;
            
            n=t.right;
            while (n!=null) {
                stack.push(n);
                n=n.left;
            }
        }
        
        if (first!=null && second!=null) {
            int tmp=first.val;
            first.val=second.val;
            second.val=tmp;
        }
    }
}
