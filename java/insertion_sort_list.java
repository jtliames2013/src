/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head==null) return null;
        ListNode sortedHead=head, restHead=head.next;
        sortedHead.next=null;
        
        while (restHead!=null) {
            ListNode node=restHead;    
            restHead=restHead.next;
            
            ListNode curr=sortedHead, prev=null;
            while (curr!=null && curr.val<node.val) {
                prev=curr;
                curr=curr.next;
            }
            
            if (prev==null) {
                node.next=sortedHead;
                sortedHead=node;
            } else {
                prev.next=node;
                node.next=curr;
            }
        }
        
        return sortedHead;
    }
}
