1362. Closest Divisors
Medium

6

5

Add to List

Share
Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.

 

Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
Example 2:

Input: num = 123
Output: [5,25]
Example 3:

Input: num = 999
Output: [40,25]
 

Constraints:

1 <= num <= 10^9

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> r1=getDiv(num+1);
        vector<int> r2=getDiv(num+2);
        return (abs(r1[0]-r1[1])<abs(r2[0]-r2[1]))?r1:r2;
    }
private:
    vector<int> getDiv(int num) {
        vector<int> mn={1, num};
        for (int i=2; i*i<=num; ++i) {
            if (num%i==0) mn={i, num/i};
        }
        return mn;
    }
};

