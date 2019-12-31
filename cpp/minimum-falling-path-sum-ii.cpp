1289. Minimum Falling Path Sum II
Hard

43

6

Add to List

Share
Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

 

Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
 

Constraints:

1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99

Google
|
LeetCode

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m=arr.size(), n=arr[0].size();
        int minidx1=-1, minidx2=-1, previdx1, previdx2;
        for (int i=0; i<m; ++i) {
            previdx1=minidx1;
            previdx2=minidx2;
            minidx1=minidx2=-1;
            for (int j=0; j<n; ++j) {
                if (j!=previdx1) arr[i][j]+=i==0?0:arr[i-1][previdx1];
                else arr[i][j]+=i==0?0:arr[i-1][previdx2];
                    
                if (minidx1==-1 || arr[i][j]<arr[i][minidx1]) {
                    minidx2=minidx1;
                    minidx1=j;
                } else if (minidx2==-1 || arr[i][j]<arr[i][minidx2]) {                    
                    minidx2=j;
                }                                
            }
            
        }
        return arr[m-1][minidx1];
    }
};


