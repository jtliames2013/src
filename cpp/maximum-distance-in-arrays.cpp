624. Maximum Distance in Arrays
DescriptionHintsSubmissionsSolutions
Total Accepted: 2506
Total Submissions: 8195
Difficulty: Easy
Contributors:
fallcreek
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:
Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
Subscribe to see which companies asked this question.

Hide Tags Array Hash Table

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res=INT_MIN, minVal=arrays[0][0], maxVal=arrays[0].back();
        
        for (int i=1; i<arrays.size(); i++) {
            res=max(res, abs(maxVal-arrays[i][0]));
            res=max(res, abs(arrays[i].back()-minVal));
            minVal=min(minVal, arrays[i][0]);
            maxVal=max(maxVal, arrays[i].back());
        }
        
        return res;
    }
};

