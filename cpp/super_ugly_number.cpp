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


