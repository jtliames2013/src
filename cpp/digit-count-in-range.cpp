1067. Digit Count in Range
Hard

27

6

Add to List

Share
Given an integer d between 0 and 9, and two positive integers low and high as lower and upper bounds, respectively. Return the number of times that d occurs as a digit in all integers between low and high, including the bounds low and high.
 

Example 1:

Input: d = 1, low = 1, high = 13
Output: 6
Explanation: 
The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1 occurs twice in the number 11.
Example 2:

Input: d = 3, low = 100, high = 250
Output: 35
Explanation: 
The digit d=3 occurs 35 times in 103,113,123,130,131,...,238,239,243.
 

Note:

0 <= d <= 9
1 <= low <= high <= 2×10^8

Amazon
|
LeetCode

The solution is based on https://leetcode.com/articles/number-of-digit-one/. Huge Kudos to the origional author of that article.

My solution extends that solution in two places.
1 when d > 0, the remainder should be larger than i * d instead of i;
2 when d == 0, when analyzing the remainder, we need avoid taking numbers with "heading zero" like 0xxxx into the total count.

class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return count(high, d)-count(low-1, d);
    }
private:
    long count(long n, int d) {
        if (n<d) return 0;
        
        long res=0;
        for (long i=1; i<=n; i*=10) {
            long div=i*10;
            res+=(n/div)*i;
            
            if (d>0) {
                res+=min(max(n%div-d*i+1, (long)0), i);
            } else {
                if (n/div>0) {
                    if (i>1) {
                        res-=i;
                        res+=min(n%div+1, i);
                    }
                }
            }
        }
        
        return res;
    }
};

