264. Ugly Number II  QuestionEditorial Solution  My Submissions
Total Accepted: 40045 Total Submissions: 131959 Difficulty: Medium
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:
The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Heap Math
Hide Similar Problems (H) Merge k Sorted Lists (E) Count Primes (E) Ugly Number (M) Perfect Squares (M) Super Ugly Number

这道题是之前那道Ugly Number 丑陋数的延伸，这里让我们找到第n个丑陋数，还好题目中给了很多提示，基本上相当于告诉我们解法了，根据提示中的信息，我们知道丑陋数序列可以拆分为下面3个子列表：

(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …

仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列，请参见代码如下：

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
	unsigned long long min(unsigned long long a, unsigned long long b, unsigned long long c) {
		if (a > b) {
			return b>c? c : b;
		} else {
			return a>c? c : a;
		}
	}

	int nthUglyNumber(int n) {
    	if (n==1) return 1;

    	vector<unsigned long long> l1, l2, l3;
    	int l1index=0, l2index=0, l3index=0;

    	l1.push_back(2);
    	l2.push_back(3);
    	l3.push_back(5);

    	while (l1.size() < n) {
    		unsigned long long m = min(l1[l1index], l2[l2index], l3[l3index]);
    		l1.push_back(m*2);
    		l2.push_back(m*3);
    		l3.push_back(m*5);
    		if (l1[l1index]==m) l1index++;
    		if (l2[l2index]==m) l2index++;
    		if (l3[l3index]==m) l3index++;
    	}

    	return l1[n-1]/2;
    }
};

int main()
{
	return 0;
}


