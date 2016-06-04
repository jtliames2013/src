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
    string multiply(string num1, string num2) {
    	string res;
    	if (num1.empty() || num2.empty()) return res;
    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());
    	int carry=0;
    	int sum=0;

    	for (int i=0; i<num1.size(); i++) {
    		for (int j=0; j<num2.size(); j++) {
    			int val=(num1[i]-'0')*(num2[j]-'0')+carry;
    			carry=val/10;
    			val%=10;
    			if (res.size()<i+j+1) {
    				res.push_back('0'+val);
    			} else {
    				sum=(res[i+j]-'0')+val;
    				if (sum>9) carry++;
    				sum%=10;
    				res[i+j]='0'+sum;
    			}
    		}
    		if (carry >0) res.push_back('0'+carry);
    		carry=0;
    	}

    	if (carry>0) res.push_back('0'+carry);
    	reverse(res.begin(),res.end());
    	int count=0;
    	for (int i=0; i<res.size()-1; i++) {
    		if (res[i]!='0') break;
    		else count++;
    	}
    	res.erase(0, count);

    	return res;
    }
};

int main()
{
	return 0;
}


