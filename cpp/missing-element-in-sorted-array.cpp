1060. Missing Element in Sorted Array
Medium

153

3

Favorite

Share
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

 

Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: A = [1,2,4], K = 3
Output: 6
Explanation: 
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
 

Note:

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8

Facebook
|
5

Amazon
|
4

Bloomberg
|
3

Google
|
2

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n=nums.size(), l=0, r=n-1, mid;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (nums[mid]-nums[0]-mid<k) l=mid;
            else r=mid-1;
        }
        return nums[0]+l+k; // nums[l]+k-(nums[l]-nums[0]-l)
    }
};

