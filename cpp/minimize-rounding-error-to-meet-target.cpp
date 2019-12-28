1058. Minimize Rounding Error to Meet Target
Medium

39

40

Add to List

Share
Given an array of prices [p1,p2...,pn] and a target, round each price pi to Roundi(pi) so that the rounded array [Round1(p1),Round2(p2)...,Roundn(pn)] sums to the given target. Each operation Roundi(pi) could be either Floor(pi) or Ceil(pi).

Return the string "-1" if the rounded array is impossible to sum to target. Otherwise, return the smallest rounding error, which is defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, as a string with three places after the decimal.

 

Example 1:

Input: prices = ["0.700","2.800","4.900"], target = 8
Output: "1.000"
Explanation: 
Use Floor, Ceil and Ceil operations to get (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 .
Example 2:

Input: prices = ["1.500","2.500","3.500"], target = 10
Output: "-1"
Explanation: 
It is impossible to meet the target.
 

Note:

1 <= prices.length <= 500.
Each string of prices prices[i] represents a real number which is between 0 and 1000 and has exactly 3 decimal places.
target is between 0 and 1000000.

Airbnb
|
LeetCode

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {        
        double res=0;
        int n=prices.size(), lower=0, upper=0;        
        vector<double> nums(n);
        for (int i=0; i<n; ++i) {
            double d=stod(prices[i]);
            int f=floor(d);
            int c=ceil(d);
            nums[i]=d-f;
            lower+=f;
            upper+=c;
        }
        if (target<lower || target>upper) return "-1";
        target-=lower;
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            if (i<n-target) res+=nums[i];
            else res+=1-nums[i];
        }
        stringstream ss;
        ss << fixed << setprecision(3) << res;
        return ss.str();        
    }
};

