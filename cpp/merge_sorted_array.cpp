#include <stdio.h>
#include <vector>
#include <queue>

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

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i = m + n - 1;
    	int aidx = m - 1;
    	int bidx = n - 1;

    	while (aidx >= 0 && bidx >= 0)
    	{
    		if (A[aidx] >= B[bidx]) A[i--] = A[aidx--];
    		else A[i--] = B[bidx--];
    	}

    	if (bidx >= 0)
    	{
    		while (bidx >= 0) A[i--] = B[bidx--];
    	}
    }
};

int main()
{
	return 0;
}

