/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head==null) return null;
        ListNode prev=null, curr=head, next=null, newHead=null;
        while (curr!=null) {
            if (curr.val==val) {
                if (prev!=null) {
                    prev.next=curr.next;
                }
            } else {
                if (newHead==null) newHead=curr;
                prev=curr;
            }
            
            curr=curr.next;
        }
        return newHead;
    }
}
