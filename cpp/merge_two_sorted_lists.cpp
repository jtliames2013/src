#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL, *tail=NULL;
        ListNode *node;
        while (l1 && l2) {
            if (l1->val>l2->val) {
                node=l2;
                l2=l2->next;
            } else {
                node=l1;
                l1=l1->next;
            }
            if (head==NULL) {
                head=tail=node;
            } else {
                tail->next=node;
                tail=node;
            }
        }
        if (l1) node=l1;
        else node=l2;
        
        if (head==NULL) {
            head=node;
        } else {
            tail->next=node;
        }
        
        return head;
    }
};

int main()
{
	return 0;
}

