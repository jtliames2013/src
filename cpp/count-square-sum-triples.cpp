1925. Count Square Sum Triples
Easy

69

10

Add to List

Share
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

 

Example 1:

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
Example 2:

Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 

Constraints:

1 <= n <= 250

class Solution {
public:
    int countTriples(int n) {
        int res=0;
        for (int i=1; i<=n; ++i) {
            for (int j=i; j<=n; ++j) {
                int sum=i*i+j*j;
                if (sum>n*n) break;
                int c=int(sqrt(sum));
                if (c*c==sum) res+=2;
            }
        }
        return res;
    }
};

