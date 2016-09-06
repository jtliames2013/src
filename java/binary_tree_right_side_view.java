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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res=new ArrayList<Integer>();
        Queue<TreeNode> q=new ArrayDeque<TreeNode>();
        if (root==null) return res;
        q.offer(root);
        int currLevel=1;
        int nextLevel=0;
        
        while (!q.isEmpty()) {
            TreeNode f=q.poll();
            currLevel--;
            if (currLevel==0) res.add(f.val);
            
            if (f.left!=null) {
                q.offer(f.left);
                nextLevel++;
            } 
            
            if (f.right!=null) {
                q.offer(f.right);
                nextLevel++;
            }
            
            if (currLevel==0) {
                currLevel=nextLevel;
                nextLevel=0;
            }
        }
        
        return res;
    }
}
