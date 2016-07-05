2. Add Two Numbers 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Company Tags Amazon Microsoft Bloomberg Airbnb Adobe
Hide Tags Linked List Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary (E) Sum of Two Integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* res=NULL;
    	ListNode* tail=NULL;
    	ListNode* l1curr=l1;
    	ListNode* l2curr=l2;
    	ListNode* curr;
    	bool carry=false;

    	while (l1curr!=NULL && l2curr!=NULL) {
    		int v=l1curr->val+l2curr->val;
    		if (carry==true) {
    			v++;
    		}
    		if (v>9) {
    			v=v%10;
    			carry=true;
    		} else {
    			carry=false;
    		}
    		ListNode* n=new ListNode(v);
    		if (res==NULL) {
    			res=n;
    			tail=n;
    		} else {
    			tail->next=n;
    			tail=n;
    		}
    		l1curr=l1curr->next;
    		l2curr=l2curr->next;
    	}

    	curr = l1curr!=NULL ? l1curr : l2curr;
    	while (curr!=NULL) {
    		int v=curr->val;
			if (carry==true) {
				v++;
			}
			if (v>9) {
				v=v%10;
				carry=true;
			} else {
				carry=false;
			}

			ListNode* n=new ListNode(v);
			if (res==NULL) {
				res=n;
				tail=n;
			} else {
				tail->next=n;
				tail=n;
			}
			curr=curr->next;
    	}

    	if (carry==true) {
    		ListNode* n=new ListNode(1);
    		tail->next=n;
    	}

    	return res;
    }
};

2.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=NULL, *tail=NULL;
        bool carry=false;
        int num;
        
        while (l1!=NULL || l2!=NULL) {
            if (l1!=NULL && l2!=NULL) {
                num=l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            } else if (l1!=NULL) {
                num=l1->val;
                l1=l1->next;
            } else {
                num=l2->val;
                l2=l2->next;
            }
            if (carry) {
                num++;
                carry=false;
            }
            if (num>9) {
                num%=10;
                carry=true;
            }
            ListNode *n=new ListNode(num);
            if (res==NULL) {
                res=tail=n;
            } else {
                tail->next=n;
                tail=n;
            }
        }
        
        if (carry) {
            ListNode *n=new ListNode(1);
            tail->next=n;
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


