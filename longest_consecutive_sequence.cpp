#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
     int longestConsecutive(vector<int>& nums) {
    	 if (nums.size()==0) return 0;
    	 unordered_set<int> table;
    	 for (int i=0; i<nums.size();i++) {
    		 table.insert(nums[i]);
    	 }
    	 int curr=0, max=0;

    	 for (int i=0; i<nums.size(); i++) {
    		 if (table.find(nums[i])!=table.end()) {
    			 curr++;
    			 table.erase(nums[i]);

    			 int j=1;
    			 while (1) {
					 if (table.find(nums[i]+j)==table.end()) {
						 break;
					 } else {
						 if (table.find(nums[i]+j)!=table.end()) {
							 table.erase(nums[i]+j);
							 curr++;
						 }
					 }
					 j++;
    			 }
    			 j=1;
    			 while (1) {
					 if (table.find(nums[i]-j)==table.end()) {
						 if (max<curr) max=curr;
						 curr=0;
						 break;
					 } else {
						 if (table.find(nums[i]-j)!=table.end()) {
							 table.erase(nums[i]-j);
							 curr++;
						 }
					 }
					 j++;
    			 }
    		 }
    	 }

    	 return max;
     }
 };

int main()
{
	return 0;
}

