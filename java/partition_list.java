/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head==null) return null;
        ListNode lessHead=null, lessTail=null, greaterHead=head;
        
        ListNode curr=head, prev=null, next;
        while (curr!=null) {
            next=curr.next;
            if (curr.val<x) {
                if (curr==greaterHead) {
                    greaterHead=next;
                } else {
                    prev.next=next;
                } 
                
                if (lessHead==null) {
                    lessHead=lessTail=curr;
                } else {
                    lessTail.next=curr;
                    lessTail=curr;
                }
                curr.next=null;
            } else {
                prev=curr;
            }
            curr=next;
        }
        
        if (lessTail!=null) {
            lessTail.next=greaterHead;
            return lessHead;
        } else {
            return greaterHead;
        }
    }
}
