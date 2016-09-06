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
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    TreeNode constructBST(int[] nums, int left, int right) {
        if (left>right) return null;
        int mid=left+(right-left)/2;
        TreeNode node=new TreeNode(nums[mid]);
        node.left=constructBST(nums, left, mid-1);
        node.right=constructBST(nums, mid+1, right);
        return node;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        return constructBST(nums, 0, nums.length-1);
    }
     
    public static void main(String[] args) {
    }
}

