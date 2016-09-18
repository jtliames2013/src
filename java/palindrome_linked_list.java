/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode one=head, two=head, curr=null, prev=null, next=null;
        if (head==null) return true;
        while (two!=null && two.next!=null) {
            prev=one;
            one=one.next;
            two=two.next.next;
        }
        
        if (prev!=null) prev.next=null;
        
        prev=null;
        curr=one;
        while (curr!=null) {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        
        ListNode l1=prev, l2=head;
        while (l2!=null) {
            if (l1.val!=l2.val) return false;
            l1=l1.next;
            l2=l2.next;
        }
        return true;
    }
}
