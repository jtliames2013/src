/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    ListNode mergeSort(ListNode head) {
        if (head==null) return null;
        if (head.next==null) return head;
        ListNode one=head, two=head, prev=null;
        while (two!=null && two.next!=null) {
            prev=one;
            one=one.next;
            two=two.next.next;
        }
        if (prev!=null) prev.next=null;
        ListNode l1=mergeSort(head);
        ListNode l2=mergeSort(one);
        ListNode newhead=null, tail=null;
        ListNode curr=null;
        while (l1!=null && l2!=null) {
            if (l1.val<l2.val) {
                curr=l1;
                l1=l1.next;
            } else {
                curr=l2;
                l2=l2.next;
            }
            
            if (newhead==null) {
                newhead=tail=curr;
            } else {
                tail.next=curr;
                tail=curr;
            }
        }
        
        if (l1!=null) {
            curr=l1;
        } else {
            curr=l2;
        }
        tail.next=curr;
        
        return newhead;
    }
    
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
   }
}
