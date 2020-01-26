1331. Rank Transform of an Array
Easy

40

1

Add to List

Share
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if (n==0) return vector<int>();
        
        vector<int> res(n);
        int rank=1;
        vector<vector<int>> comb;
        for (int i=0; i<n; ++i) comb.push_back({arr[i], i});
        sort(comb.begin(), comb.end(), [](vector<int>& a, vector<int>& b){ return a[0]<b[0]; });
        res[comb[0][1]]=rank;
        for (int i=1; i<n; ++i) {
            if (comb[i][0]!=comb[i-1][0]) rank++;
            res[comb[i][1]]=rank;
        }
        return res;
    }
};

