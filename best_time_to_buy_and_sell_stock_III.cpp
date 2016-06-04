(n^2)的算法很容易想到：
找寻一个点j，将原来的price[0..n-1]分割为price[0..j]和price[j..n-1]，分别求两段的最大profit。
进行优化：
对于点j+1，求price[0..j+1]的最大profit时，很多工作是重复的，在求price[0..j]的最大profit中已经做过了。
类似于Best Time to Buy and Sell Stock，可以在O(1)的时间从price[0..j]推出price[0..j+1]的最大profit。
但是如何从price[j..n-1]推出price[j+1..n-1]？反过来思考，我们可以用O(1)的时间由price[j+1..n-1]推出price[j..n-1]。
最终算法：
数组l[i]记录了price[0..i]的最大profit，
数组r[i]记录了price[i..n]的最大profit。
已知l[i]，求l[i+1]是简单的，同样已知r[i]，求r[i-1]也很容易。
最后，我们再用O(n)的时间找出最大的l[i]+r[i]，即为题目所求。

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
     int maxProfit(vector<int>& prices) {
    	 int size=prices.size();
    	 if (size==0) return 0;
    	 vector<int> left(size, 0);
    	 vector<int> right(size, 0);
    	 int minp=prices[0];
    	 left[0]=0;

    	 for (int i=1; i<prices.size(); i++) {
    		 left[i] = max(left[i-1], prices[i]-minp);
    		 minp = min(minp, prices[i]);
    	 }

    	 right[size-1]=0;
    	 int maxp=prices[size-1];
    	 for (int i=prices.size()-1; i>0; i--) {
    		 right[i-1] = max(right[i], maxp-prices[i-1]);
    		 maxp = max(maxp, prices[i-1]);
    	 }

    	 int maxres=0;
    	 for (int i=0; i<size; i++) {
    		 if (maxres < left[i]+right[i]) {
    			 maxres = left[i]+right[i];
    		 }
    	 }

    	 return maxres;
     }
 };

int main()
{
	return 0;
}


