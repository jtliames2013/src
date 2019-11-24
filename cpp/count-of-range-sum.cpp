327. Count of Range Sum
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
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

First of all, let's look at the naive solution. Preprocess to calculate the prefix sums S[i] = S(0, i), then S(i, j) = S[j] - S[i]. Note that here we define S(i, j) as the sum of range [i, j) where j exclusive and j > i. With these prefix sums, it is trivial to see that with O(n^2) time we can find all S(i, j) in the range [lower, upper]

Recall count smaller number after self where we encountered the problem

count[i] = count of nums[j] - nums[i] < 0 with j > i
Here, after we did the preprocess, we need to solve the problem

count[i] = count of a <= S[j] - S[i] <= b with j > i
ans = sum(count[:])
Therefore the two problems are almost the same. We can use the same technique used in that problem to solve this problem. One solution is merge sort based; another one is Balanced BST based. The time complexity are both O(n log n).

The merge sort based solution counts the answer while doing the merge. During the merge stage, we have already sorted the left half [start, mid) and right half [mid, end). We then iterate through the left half with index i. For each i, we need to find two indices k and j in the right half where

j is the first index satisfy sums[j] - sums[i] > upper and
k is the first index satisfy sums[k] - sums[i] >= lower.
Then the number of sums in [lower, upper] is j-k. We also use another index t to copy the elements satisfy sums[t] < sums[i] to a cache in order to complete the merge sort.

Despite the nested loops, the time complexity of the "merge & count" stage is still linear. Because the indices k, j, t will only increase but not decrease, each of them will only traversal the right half once at most. The total time complexity of this divide and conquer solution is then O(n log n).

One other concern is that the sums may overflow integer. So we use long instead.


First of all, we get the sum array. Then, we divide the array by halves. The range can exist inside the first and second half, 
it can also exist across the first and second half. Then for a range [start, end], the recursion becomes:

in the first half + # in the second half + # across the first and second half.
How to get the # in the first and second half? The above recursion still applies!

Then, the question becomes how to count the # across the first and second half. What happens the first half and second half 
are sorted after we count the # inside them? It becomes quite simple to get the cross result. It becomes a two pointer question.

The use a low pointer to get the first index that satisfies sum[low] - sum[i] >= lower, and get the last index 
that satisfies sum[high] - sum[i] >= upper. The # of cross result that can be formed with i as the left index is upper - lower. 
Since the first half is sorted, sum[i + 1] >= sum[i], then, low and high do not need to go back. Therefore, it is O(N) operation.


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        if (n==0) return 0;
        vector<long> sums(n+1);
        for (int i=1; i<=n; ++i) sums[i]=sums[i-1]+nums[i-1];
        return mergeSortCount(sums, 0, n, lower, upper);
    }
private:
    int mergeSortCount(vector<long>& sums, int start, int end, int lower, int upper) {
        if (start>=end) return 0;
        int mid=start+(end-start)/2;
        int count=mergeSortCount(sums, start, mid, lower, upper) + mergeSortCount(sums, mid+1, end, lower, upper);
        vector<long> tmp(end-start+1);
        int k=mid+1, j=mid+1, i1=start, i2=mid+1, t=0;
        for (; i1<=mid; ++i1) {
            while (k<=end && sums[k]-sums[i1]<lower) k++;
            while (j<=end && sums[j]-sums[i1]<=upper) j++;
            while (i2<=end && sums[i2]<sums[i1]) tmp[t++]=sums[i2++];
            tmp[t++]=sums[i1];
            count+=j-k;
        }
        copy(tmp.begin(), tmp.begin()+i2-start, sums.begin()+start);
        return count;
    }
};


