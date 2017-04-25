334. Increasing Triplet Subsequence

 Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false. 

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

Hide Company Tags Facebook
Hide Similar Problems (M) Longest Increasing Subsequence

维护变量a, b，用来记录数组中大小递增的前2个元素。
遍历数组nums，记当前元素为n
  若a为空或者a >= n，则令a = n；
  否则，若b为空或者b >= n，则令b = n；
  否则，返回true
遍历结束时，返回false。
[3, 6, 1, 9]

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a=LLONG_MAX, b=LLONG_MAX;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=a) a=nums[i];
            else if (nums[i]<=b) b=nums[i];
            else return true;
        }
        return false;
    }
};

