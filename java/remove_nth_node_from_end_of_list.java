/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head==null) return null;
        ListNode tail=head, curr=head, prev=null, newHead=head;
        while (tail!=null && n>0) {
            tail=tail.next;
            n--;
        }
        
        while (tail!=null) {
            prev=curr;
            curr=curr.next;
            tail=tail.next;
        }
        
        if (prev==null) {
            newHead=curr.next;
        } else {
            prev.next=curr.next;
        }
        return newHead;
    }
}
