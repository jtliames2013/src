import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class HelloWorld {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val=x; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head=null, tail=null;
        boolean carry=false;
        while (l1!=null || l2!=null) {
            int num;
            if (l1!=null && l2!=null) {
                num=l1.val+l2.val;
                l1=l1.next;
                l2=l2.next;
            } else if (l1!=null) {
                num=l1.val;
                l1=l1.next;
            } else {
                num=l2.val;
                l2=l2.next;
            }
            if (carry==true) {
                num++;
                carry=false;
            }
            if (num>9) {
                num%=10;
                carry=true;
            }
            ListNode n=new ListNode(num);
            if (head==null) {
                head=tail=n;
            } else {
                tail.next=n;
                tail=n;
            }
        }
        
        if (carry==true) {
            ListNode n=new ListNode(1);
            tail.next=n;
        }
        
        return head;
    }
    
    public static void main(String[] args) {

    }
}

