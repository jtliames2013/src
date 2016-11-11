/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root==null) return;
        if (root.left!=null) {
            TreeLinkNode curr=root.next;
            if (root.right!=null) root.left.next=root.right;
            else {
                while (curr!=null) {
                    if (curr.left!=null) {
                        root.left.next=curr.left;
                        break;
                    } else if (curr.right!=null) {
                        root.left.next=curr.right;
                        break;
                    }
                    curr=curr.next;    
                }
            }
        }
        if (root.right!=null) {
            TreeLinkNode curr=root.next;
            while (curr!=null) {
                if (curr.left!=null) {
                    root.right.next=curr.left;
                    break;
                } else if (curr.right!=null) {
                    root.right.next=curr.right;
                    break;
                }
                curr=curr.next;    
            }
        }
        connect(root.right);
        connect(root.left);
    }
}

