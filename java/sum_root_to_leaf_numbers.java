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
    int sum;
    void sumNumbers(TreeNode root, int num) {
        if (root==null) return;
        int curr=num*10+root.val;
        if (root.left==null && root.right==null) {
            sum+=curr;
            return;
        }
        
        if (root.left!=null) {
            sumNumbers(root.left, curr);
        }
        
        if (root.right!=null) {
            sumNumbers(root.right, curr);
        }
    }
    public int sumNumbers(TreeNode root) {
        int num=0;
        sum=0;
        sumNumbers(root, num);
        return sum;
    }
}
