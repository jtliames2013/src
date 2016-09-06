/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if (head==null) return null;
        ListNode one=head, prev=null, next, two=head;
        while (two!=null && two.next!=null) {
            prev=one;
            one=one.next;            
            two=two.next.next;            
        }
        
        TreeNode node=new TreeNode(one.val);
        if (prev!=null) prev.next=null;
        next=one.next;
        one.next=null;               
        node.left=sortedListToBST(one==head?null:head);
        node.right=sortedListToBST(next);
        return node;
    }
}

