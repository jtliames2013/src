/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head==null) return null;
        int size=0;
        ListNode curr=head, tail=null, prev=null;
        while (curr!=null) {
            size++;
            tail=curr;
            curr=curr.next;
        }
        k%=size;
        int n=size-k;
        curr=head;
        if (k>0) {
            while (n>0) {
                n--;
                prev=curr;
                curr=curr.next;
            }
            prev.next=null;
            tail.next=head;
        }
        return curr;
    }
}
