import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import java.util.PriorityQueue;
import java.lang.Math;

public class HelloWorld {    
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    public List<TreeNode> generateTrees(int l, int r) {
        List<TreeNode> res=new ArrayList<TreeNode>();
        if (l>r) {
            res.add(null);
            return res;
        }
        for (int i=l; i<=r; i++) {            
            List<TreeNode> left=generateTrees(l, i-1);
            List<TreeNode> right=generateTrees(i+1, r);
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode node=new TreeNode(i);
                    node.left=left.get(j);
                    node.right=right.get(k);
                    res.add(node);
                }
            }                       
        }
        
        return res;
    }
    
    public List<TreeNode> generateTrees(int n) {
        if (n==0) return new ArrayList<TreeNode> ();
        return generateTrees(1, n);
    }
         
    public static void main(String[] args) {
    }
}

