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
    void getPath(List<String> res, List<TreeNode> path, TreeNode node) {
        if (node==null) return;
        path.add(node);
        if (node.left==null && node.right==null) {
            String str=new String();
            for (int i=0; i<path.size(); i++) {
                if (i>0) {
                    str+="->";
                }
                str+=Integer.toString(path.get(i).val);
            }
            res.add(str);
            path.remove(path.size()-1);
            return;
        }
        
        if (node.left!=null) getPath(res, path, node.left);
        if (node.right!=null) getPath(res, path, node.right);
        
        path.remove(path.size()-1);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res=new ArrayList<>();
        if (root==null) return res;
        List<TreeNode> path=new ArrayList<>();
        getPath(res, path, root);
        
        return res;
    }
}
