1131. Maximum of Absolute Value Expression
Medium

62

79

Favorite

Share
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res=0, n=arr1.size(), mx, mn, dist;
        for (auto a:{-1, 1}) {
            for (auto b:{-1, 1}) {
                mx=INT_MIN;
                mn=INT_MAX;
                for (int i=0; i<n; ++i) {
                    dist=a*arr1[i]+b*arr2[i]+i;
                    mx=max(mx, dist);
                    mn=min(mn, dist);
                    res=max(res, mx-mn);                    
                }
            }
        }
        return res;
    }
};
