483. Smallest Good Base Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 3196
Total Submissions: 10163
Difficulty: Hard
Contributors:
ckcz123
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format. 

Example 1:
Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.
Example 2:
Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.
Example 3:
Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.
Note:
The range of n is [3, 10^18].
The string representing n is always valid and will not have leading zeros.
Subscribe to see which companies asked this question.

Hide Tags Binary Search Math

n = k^m + k^(m-1) + ... + k + 1
k*n+1 = k^(m+1) + k^m + ... + k^2 + k + 1
k*n+1 = k^(m+1) + n
(k-1)*n = k^(m+1) - 1

class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num=stoull(n);
        unsigned long long bound=log2(num);
        for (unsigned long long m=bound; m>=1; m--) {
            unsigned long long k=pow(num, 1.0/m);
            if ((((unsigned long long)pow(k, m+1)-1)/(k-1))==num) {
                return to_string(k);
            }
        }

        return to_string(num-1);
    }
};

