/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	var tail *ListNode
	carry := false
	for l1 != nil || l2 != nil {
		num := 0
		if l1 != nil && l2 != nil {
			num = l1.Val + l2.Val
			l1 = l1.Next
			l2 = l2.Next
		} else if l1 != nil {
			num = l1.Val
			l1 = l1.Next
		} else {
			num = l2.Val
			l2 = l2.Next
		}
		if carry {
			num++
			carry = false
		}
		if num > 9 {
			num %= 10
			carry = true
		}
		if head == nil {
			head = &ListNode{num, nil}
			tail = head
		} else {
			tail.Next = &ListNode{num, nil}
			tail = tail.Next
		}
	}
	if carry {
		tail.Next = &ListNode{1, nil}
	}
	return head
}

