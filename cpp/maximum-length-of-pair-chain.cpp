646. Maximum Length of Pair Chain
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if (n==0) return 0;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) { return a[1]<b[1]; });
        
        int end=pairs[0][1], count=0;
        for (int i=1; i<n; i++) {
            if (pairs[i][0]<=end) count++;
            else end=pairs[i][1];
        }
        return n-count;
    }
};

2.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if (n==0) return 0;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) { return a[1]<b[1]; });
        
        int end=pairs[0][1], count=1;
        for (int i=1; i<n; i++) {
            if (pairs[i][0]>end) {
                count++;
                end=pairs[i][1];
            }
        }
        return count;
    }
};

