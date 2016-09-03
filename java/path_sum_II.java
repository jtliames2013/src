import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class HelloWorld {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode (int x) { val=x; }
    }
    public void getPath(List<List<Integer>> res, List<Integer> path, TreeNode root, int sum) {
        if (root==null) return;
        path.add(root.val);
        if (root.val==sum && root.left==null && root.right==null) {
            res.add(new ArrayList<Integer>(path));
            path.remove(path.size()-1);
            return;
        }

        if (root.left!=null) {
            getPath(res, path, root.left, sum-root.val);
        }
        
        if (root.right!=null) {
            getPath(res, path, root.right, sum-root.val);
        }
        path.remove(path.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> path=new ArrayList<Integer>();
        getPath(res, path, root, sum);
        
        return res;
    }

    public static void main(String[] args) {

    }
}

