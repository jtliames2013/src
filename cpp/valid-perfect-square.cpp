367. Valid Perfect Square 
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags LinkedIn
Hide Tags Binary Search Math
Hide Similar Problems (M) Sqrt(x)

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=1, r=num, mid;
        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (mid*mid==num) return true;
            else if (mid*mid<num) l=mid+1;
            else r=mid-1;
        }
        
        return false;
    }
};

