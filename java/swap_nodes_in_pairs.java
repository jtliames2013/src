/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode newHead=head, prevEnd=null, start=head, end=null, nextStart=null;
        if (start!=null) end=start.next;
        if (end!=null) nextStart=end.next;
        while (end!=null) {
            end.next=start;
            start.next=nextStart;
            if (prevEnd==null) {
                newHead=end;
            } else {
                prevEnd.next=end;
            }
            prevEnd=start;
            start=nextStart;
            end=(start!=null?start.next:null);
            nextStart=(end!=null?end.next:null);
        }
        
        return newHead;
    }
}
