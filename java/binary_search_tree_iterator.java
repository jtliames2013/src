/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    
    Stack<TreeNode> stack;
    public BSTIterator(TreeNode root) {
        stack=new Stack<>();
        TreeNode n=root;
        while (n!=null) {
            stack.push(n);
            n=n.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return stack.empty()==false;
    }

    /** @return the next smallest number */
    public int next() {
        if (hasNext()==true) {
            TreeNode t=stack.pop();
            TreeNode n=t.right;
            while (n!=null) {
                stack.push(n);
                n=n.left;
            }
            return t.val;
        } else {
            return -1;
        }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
