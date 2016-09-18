/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head==null) return null;
        ListNode curr=head, prev=null, next=null, newHead=null;
        
        while (curr!=null) {
            next=curr.next;
            boolean isDup=false;
            while (next!=null && next.val==curr.val) {
                next=next.next;
                isDup=true;
            }
            
            if (!isDup) {
                if (newHead==null) {
                    newHead=curr;
                }
                prev=curr;
            } else {
                if (prev!=null) prev.next=next;
            }

            curr=next;
        }
        return newHead;
    }
}
