949. Largest Time for Given Digits
Easy

42

126

Favorite

Share
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        string res;
        do {
            int h=A[0]*10+A[1], m=A[2]*10+A[3];
            if (h<24 && m<60) {
                string s="00:00";
                s[0]+=A[0]; s[1]+=A[1]; s[3]+=A[2]; s[4]+=A[3];                
                res=res.empty()?s:max(s,res);
            }
        } while (next_permutation(A.begin(), A.end()));
        
        return res;
    }
};

