/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head==null) return null;
        if (k<=0) return head;
        ListNode prevEnd=null, start=head, end=null, nextStart=head, curr, next, tmp;
        ListNode newHead=head;
        
        while (true) {
            int count=k;
            while (nextStart!=null && count>0) {
                end=nextStart;
                nextStart=nextStart.next;
                count--;
            }
            if (count>0) break;
            
            // prevEnd->start->...->end->nextStart
            // keep remove start and insert after end
            curr=start;
            while (curr!=end) {
                next=curr.next;
                tmp=end.next;
                end.next=curr;
                curr.next=tmp;
                curr=next;
            }
            
            if (prevEnd==null) {
                newHead=end;
            } else {
                prevEnd.next=end;
            }
            prevEnd=start;
            end=start;
            start=nextStart;
        }
        
        return newHead;
    }
}
