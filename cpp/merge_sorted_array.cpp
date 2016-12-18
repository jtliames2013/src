#include <stdio.h>
#include <vector>
#include <queue>

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

2.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index=m+n-1;
        int i=m-1, j=n-1;
        while (i>=0&&j>=0) {
            if (nums1[i]<nums2[j]) nums1[index--]=nums2[j--];
            else nums1[index--]=nums1[i--];
        }
        while (j>=0) nums1[index--]=nums2[j--];
    }
};

int main()
{
	return 0;
}

