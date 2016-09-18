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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        if (root==null) return res;
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode t=stack.pop();
            res.add(t.val);
            
            if (t.right!=null) {
                stack.push(t.right);
            }
            if (t.left!=null) {
                stack.push(t.left);
            }
        }
        return res;
    }
}
