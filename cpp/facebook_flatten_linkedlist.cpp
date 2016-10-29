Flatten linked list
Struct{
  int val;
  Struct next, child;
}
e.g.
3 -> 4 -> 5
        |
        6 -> 7
        |
        8 -> 9
return 3 -> 4 -> 6 -> 8 -> 9 -> 7 -> 5

struct ListNode {
	int val;
	ListNode *next;
	ListNode *child;
	ListNode(int v):val(v),next(NULL),child(NULL) {}
};

class Solution {
public:
	void flatten(ListNode* head, ListNode **last) {
		if (head==NULL) return;
		*last=head;
		ListNode* next=head->next;
		if (head->child) {
			ListNode *childLast=NULL;
			flatten(head->child, &childLast);
			*last=childLast;
			head->next=head->child;
			head->child=NULL;
		}
		if (next) {
			ListNode *nextLast=NULL;
			flatten(next, &nextLast);
			(*last)->next=next;
			*last=nextLast;
		}
	}
	void flatten(ListNode *head) {
		ListNode *last=NULL;
		flatten(head, &last);
	}
};

int main()
{
	ListNode *head=new ListNode(3);
	ListNode *n4=new ListNode(4);
	head->next=n4;
	ListNode *n5=new ListNode(5);
	n4->next=n5;
	ListNode *n6=new ListNode(6);
	n4->child=n6;
	ListNode *n7=new ListNode(7);
	n6->next=n7;
	ListNode *n8=new ListNode(8);
	n6->child=n8;
	ListNode *n9=new ListNode(9);
	n8->next=n9;

	Solution s;
	s.flatten(head);
	for (ListNode* curr=head; curr!=NULL; curr=curr->next) {
		cout << curr->val << " ";
	}
	cout << endl;
	return 0;
}

