/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head=null, tail=null;
        while (l1!=null && l2!=null) {
            ListNode l;
            if (l1.val<l2.val) {
                l=l1;
                l1=l1.next;
            } else {
                l=l2;
                l2=l2.next;
            }
            if (head==null) {
                head=tail=l;
            } else {
                tail.next=l;
                tail=l;
            }
        }
        
        if (l1!=null) {
            if (head==null) {
                head=l1;
            } else {
                tail.next=l1;
            }
        } else if (l2!=null) {
            if (head==null) {
                head=l2;
            } else {
                tail.next=l2;
            }
        }
        
        return head;
    }
}
