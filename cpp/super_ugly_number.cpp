313. Super Ugly Number  QuestionEditorial Solution  My Submissions
Total Accepted: 22072 Total Submissions: 61035 Difficulty: Medium
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Math Heap
Hide Similar Problems (M) Ugly Number II

这道题让我们求超级丑陋数，是之前那两道Ugly Number 丑陋数和Ugly Number II 丑陋数之二的延伸，质数集合可以任意给定，这就增加了难度。但是本质上和Ugly Number II 丑陋数之二没有什么区别，由于我们不知道质数的个数，我们可以用一个idx数组来保存当前的位置，然后我们从每个子链中取出一个数，找出其中最小值，然后更新idx数组对应位置，注意有可能最小值不止一个，要更新所有最小值的位置，参见代码如下：

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
	unsigned long long min(vector<unsigned long long>& vals) {
		unsigned long long res = vals[0];

		for (int i=1; i<vals.size(); i++) {
			if (res > vals[i]) res = vals[i];
		}

		return res;
	}

    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	int psize=primes.size();
    	if (psize==0) return 1;

    	vector<int> res(n);
    	vector<unsigned long long> vals(psize);
    	vector<int> index(psize);
    	res[0]=1;
    	for (int i=0; i<psize; i++) {
    		vals[i]=primes[i];
    		index[i]=0;
    	}

    	for (int i=1; i<n; i++) {
    		unsigned long long m = min(vals);
    		res[i]=m;

    		for (int j=0; j<psize; j++) {
    			if (vals[j]==m) {
    				index[j]++;
    				vals[j] = res[index[j]]*primes[j];
    			}
    		}
    	}

    	return res[n-1];
    }
};

int main()
{
	return 0;
}


