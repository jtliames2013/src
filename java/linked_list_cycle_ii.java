/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode one=head, two=head;
        while (two!=null && two.next!=null) {
            one=one.next;
            two=two.next.next;
            if (one==two) break;
        }
        
        if (two==null || two.next==null) return null;
        
        one=head;
        while (one!=two) {
            one=one.next;
            two=two.next;
        }
        
        return one;
    }
}
