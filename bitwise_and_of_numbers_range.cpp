解题思路：
由数据范围0 <= m <= n <= 2147483647可知，时间复杂度O（n）及以上的解法是不可接受的。

因此可以判断此题为数学题。

参考LeetCode Discuss链接：https://leetcode.com/discuss/32053/accepted-c-solution-with-simple-explanation

[m, n]范围的按位与的结果为m与n的公共“左边首部（left header）”

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
    int rangeBitwiseAnd(int m, int n) {
    	int count=0;

    	while (m!=n) {
    		m>>=1;
    		n>>=1;
    		count++;
    	}

    	return n<<count;
    }
};

int main()
{
	return 0;
}


