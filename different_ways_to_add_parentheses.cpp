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
#include <math.h>

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
	int compute(int a, int b, char op) {
		switch (op) {
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		}
	}

    vector<int> diffWaysToCompute(string input) {
    	vector<int> res;
    	if (input.size()==0) return res;

    	int num=0;
    	bool singleNum=true;
    	for (int i=0; i<input.size(); i++) {
    		if (!isdigit(input[i])) {
    			singleNum=false;
    			break;
    		} else {
    			num *= 10;
    			num += input[i]-'0';
    		}
    	}

    	if (singleNum) {
    		res.push_back(num);
    	} else {
    		for (int i=0; i<input.size(); i++) {
    			if (isdigit(input[i])) continue;

    			vector<int> left = diffWaysToCompute(input.substr(0, i));
    			vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()-i-1));

    			for (int j=0; j<left.size(); j++) {
    				for (int k=0; k<right.size(); k++) {
    					res.push_back(compute(left[j], right[k], input[i]));
    				}
    			}
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


