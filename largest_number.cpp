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
    string largestNumber(vector<int>& nums) {
    	string res;
    	vector<string> numstr;
    	char buf[16];
    	for (int i=0; i<nums.size(); i++) {
    		sprintf(buf, "%d", nums[i]);
    		numstr.push_back(buf);
    	}

    	sort(numstr.begin(), numstr.end(), [](string a, string b) {
    		string s1=a; s1.append(b);
    		string s2=b; s2.append(a);
    		return s1.compare(s2)>0;
    	});

    	for (int i=0; i<numstr.size(); i++) {
    		res.append(numstr[i].c_str());
    	}

    	while (res.size()>1) {
    		if (*(res.begin())=='0') res.erase(res.begin());
    		else break;
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

