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
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int, int> m;
    	vector<int> res;

    	for(int i=0; i<nums.size(); i++) {
    		m.insert(make_pair(nums[i], i+1));
    	}

    	for(int i=0; i<nums.size(); i++) {
    		auto n=m.find(target-nums[i]);
    		if (n!=m.end() && (*n).second != i+1) {
    			res.push_back(i+1<(*n).second ? i+1 : (*n).second );
    			res.push_back(i+1<(*n).second ? (*n).second : i+1 );
    			break;
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


