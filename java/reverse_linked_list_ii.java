/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head==null) return null;
        ListNode oneStart=null, oneEnd=null, twoStart=null, twoEnd=null, threeStart=null;
        ListNode curr=head, prev=null;
        while (curr!=null) {
            m--;
            n--;
            if (m==0) {
                oneStart=(curr==head?null:head);
                oneEnd=prev;
                twoStart=curr;
                if (oneEnd!=null) oneEnd.next=null;
            }
            if (n==0) {
                twoEnd=curr;
                threeStart=curr.next;
                twoEnd.next=null;
                break;
            }
            
            prev=curr;
            curr=curr.next;
        }
        
        prev=null;
        curr=twoStart;
        while (curr!=null) {
            ListNode next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        
        twoStart.next=threeStart;
        if (oneEnd!=null) {
            oneEnd.next=prev;
            return oneStart;
        } else {
            return prev;
        }
    }
}
