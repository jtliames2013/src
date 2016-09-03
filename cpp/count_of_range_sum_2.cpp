327. Count of Range Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 8081 Total Submissions: 29496 Difficulty: Hard
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Divide and Conquer Binary Search Tree
Show Similar Problems

#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;


//Recall count smaller number after self where we encountered the problem
//•count[i] = count of nums[j] - nums[i] < 0 with j > i
//
//Here, after we did the preprocess, we need to solve the problem
//•count[i] = count of a <= S[j] - S[i] <= b with j > i
//•ans = sum(count[:])
//
//Therefore the two problems are almost the same. We can use the same technique used in that problem to solve this problem. One solution is merge sort based; another one is Balanced BST based. The time complexity are both O(n log n).
//
//The merge sort based solution counts the answer while doing the merge. During the merge stage, we have already sorted the left half [start, mid) and right half [mid, end). We then iterate through the left half with index i. For each i, we need to find two indices k and j in the right half where
//•j is the first index satisfy sums[j] - sums[i] > upper and 
//•k is the first index satisfy sums[k] - sums[i] >= lower. 
//
//Then the number of sums in [lower, upper] is j-k. We also use another index t to copy the elements satisfy sums[t] < sums[i] to a cache in order to complete the merge sort.
//
//Despite the nested loops, the time complexity of the "merge & count" stage is still linear. Because the indices k, j, t will only increase but not decrease, each of them will only traversal the right half once at most. The total time complexity of this divide and conquer solution is then O(n log n).
//
//One other concern is that the sums may overflow integer. So we use long instead.


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size=nums.size();
        if(size==0)  return 0;
        vector<long> sums(size+1, 0);
        for(int i=0; i<size; i++)  sums[i+1]=sums[i]+nums[i];
        return help(sums, 0, size+1, lower, upper);
    }

    /*** [start, end)  ***/
    int help(vector<long>& sums, int start, int end, int lower, int upper){
        /*** only-one-element, so the count-pair=0 ***/
        if(end-start<=1)  return 0;
        int mid=(start+end)/2;
        int count=help(sums, start, mid, lower, upper)
                + help(sums, mid, end, lower, upper);

        int m=mid, n=mid, t=mid, len=0;
        /*** cache stores the sorted-merged-2-list ***/
        /*** so we use the "len" to record the merged length ***/
        vector<long> cache(end-start, 0);
        for(int i=start, s=0; i<mid; i++, s++){
            /*** wrong code: while(m<end && sums[m++]-sums[i]<lower);  ***/
            while(m<end && sums[m]-sums[i]<lower) m++;
            while(n<end && sums[n]-sums[i]<=upper) n++;
            count+=n-m;
            /*** cache will merge-in-the-smaller-part-of-list2 ***/
            while(t<end && sums[t]<sums[i]) cache[s++]=sums[t++];
            cache[s]=sums[i];
            len=s;
        }

        for(int i=0; i<=len; i++)  sums[start+i]=cache[i];
        return count;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
