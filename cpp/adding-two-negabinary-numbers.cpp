1073. Adding Two Negabinary Numbers
Medium

65

36

Favorite

Share
Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

 

Example 1:

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
 

Note:

1 <= arr1.length <= 1000
1 <= arr2.length <= 1000
arr1 and arr2 have no leading zeros
arr1[i] is 0 or 1
arr2[i] is 0 or 1

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int m=arr1.size(), n=arr2.size(), i=m-1, j=n-1, num=0;
        for (; i>=0 || j>=0 || num; ) {
            if (i>=0) num+=arr1[i--];
            if (j>=0) num+=arr2[j--];
            res.push_back(num&1);
            num=-(num>>1);
        }
        
        while (res.size()>1 && res.back()==0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
