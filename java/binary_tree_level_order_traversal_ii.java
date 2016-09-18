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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        if (root==null) return res;
        ArrayDeque<TreeNode> queue=new ArrayDeque<>();
        int currLevel=1, nextLevel=0;
        List<Integer> level=new ArrayList<>();
        queue.offer(root);
    
        while (!queue.isEmpty()) {
            TreeNode f=queue.poll();
            level.add(f.val);
            currLevel--;
            
            if (f.left!=null) {
                queue.offer(f.left);
                nextLevel++;
            }
            if (f.right!=null) {
                queue.offer(f.right);
                nextLevel++;
            }
            
            if (currLevel==0) {
                res.add(new ArrayList(level));
                level.clear();
                currLevel=nextLevel;
                nextLevel=0;
            }
        }
    
        Collections.reverse(res);
        return res;
    }
}
