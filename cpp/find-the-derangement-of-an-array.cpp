634. Find the Derangement of An Array
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 106].

Amazon
|
2

IXL
|
LeetCode

https://en.wikipedia.org/wiki/Derangement#Counting_derangements

class Solution {
public:
    int findDerangement(int n) {
        long res=1;
        for (int i=1; i<=n; i++) 
            res=(i*res%mod + (i%2==0?1:-1))%mod;
        return res;        
    }
private:
    const int mod = pow(10, 9) + 7;        
};

