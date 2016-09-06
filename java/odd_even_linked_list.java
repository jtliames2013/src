/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode oddHead=null, evenHead=null, oddTail=null, evenTail=null;
        ListNode curr=head, next, nextnext;
        
        while (curr!=null) {
            next=curr.next;
            if (next!=null) {
                nextnext=next.next;
            } else {
                nextnext=null;
            }
            if (oddHead==null) {
                oddHead=oddTail=curr;
            } else {
                oddTail.next=curr;
                oddTail=curr;
            }
            
            if (evenHead==null) {
                evenHead=evenTail=next;
            } else {
                evenTail.next=next;
                evenTail=next;
            }
            
            curr=nextnext;
        }
        
        if (oddTail!=null) oddTail.next=evenHead;
        
        return oddHead;
    }
}
