/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head==null) return;
        ListNode one=head, two=head, prev=null;
        while (two!=null) {
            prev=one;
            one=one.next;
            two=two.next;
            if (two!=null) two=two.next;
        }
        
        prev.next=null;
        ListNode curr=one, next;
        while (curr!=null) {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        
        ListNode l1=head, l2=prev, l1next, l2next;
        while (l1!=null) {
            l1next=l1.next;
            l2next=l2.next;
            l1.next=l2;
            l2.next=l1next;
            l1=l1next;
            l2=l2next;
        }
    }
}
