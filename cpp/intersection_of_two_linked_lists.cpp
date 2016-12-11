#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA, *b=headB;
        int alen=0, blen=0;

        while (a!=NULL) { alen++; a=a->next; }
        while (b!=NULL) { blen++; b=b->next; }
        
        a=headA;
        b=headB;
        if (alen>blen) {
            while (alen>blen) { alen--; a=a->next; }
        } else if (blen>alen) {
            while (blen>alen) { blen--; b=b->next; }
        }
        
        while (a!=NULL) {
            if (a==b) return a;
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};

2.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA, *currB, *n;
        int alen=0, blen=0;
        n=headA;
        while (n!=NULL) { alen++; n=n->next; }
        n=headB;
        while (n!=NULL) { blen++; n=n->next; }
     
        int delta;
        currA=headA;
        currB=headB;
        if (alen>blen) {
            delta=alen-blen;
            while (delta>0) { delta--; currA=currA->next; }
        } else {
            delta=blen-alen;
            while (delta>0) { delta--; currB=currB->next; }
        }        

        while (currA!=NULL && currB!=NULL) {
            if (currA==currB) return currA;
            currA=currA->next;
            currB=currB->next;
        }
        
        return NULL;
    }
};

3. 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA, *b=headB;
        bool aTob=false, bToa=false;
        
        while (1) {
            if (a==b) return a;
            else {
                a=a->next;
                if (a==NULL) {
                    if (aTob==false) {
                        a=headB;
                        aTob=true;
                    } else {
                        break;
                    }
                } 
                
                b=b->next;
                if (b==NULL) {
                    if (bToa==false) {
                        b=headA;
                        bToa=true;
                    } else  {
                        break;
                    }
                }
            }
        }
        return NULL;
    }
};

int main()
{
	return 0;
}

