1012. Numbers With Repeated Digits
Hard

115

35

Favorite

Share
Given a positive integer N, return the number of positive integers less than or equal to N that have at least 1 repeated digit.

 

Example 1:

Input: 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
Example 2:

Input: 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
Example 3:

Input: 1000
Output: 262
 

Note:

1 <= N <= 10^9

The number of non-repeated digits can be easily calculated with permutaiton. We only need to exclude all the non-repeated digits to get the answer.

Let's first consider about the cases where N=10^k
N=10
the free digits are marked as *, so we only need to consider about * and 1*

*: obviously all 1-digit numbers are non-repeated, so non-repeated number = 9
1*: we only need to consider about 1* <= 10, so non-repeated number = 1
Thus, the result for N=10 is:
N - #non_repeat(*) - #non_repeat(1*) = 10 - 9 - 1 = 0

N=100
the free digits are marked as *, so we only need to consider about *, **, and 1**

*: obviously all 1-digit numbers are non-repeated, so non-repeated number = 9
**: this can be calculated with permutation: leading digit has 9 options(1-9) and the last 1 digit has 10-1 options, thus the total permuation is 9 * permutation(9, 1)=81. i.e: non-repeated number = 81
1**: we only need to consider about 1**<=100, so non-repeated number =0
Thus, the result for N=100 is:
N - #non_repeat(*) - #non_repeat(**) - #non_repeat(1**) = 100 - 9 - 81 = 10

N=1000
#non_repeat(***) = 9 * permutation(9, 2) = 9 * 9 * 8 = 648
similarly, we can get:
N - #non_repeat(*) - #non_repeat(**) - #non_repeat(***) - #non_repeat(1***) = 1000 - 9 - 81 - 648 = 282

Now, let's consider a more general case:
N=12345
actually, we can get the count of non-repeated numbers by counting all non-repeated numbers in following patterns:

    *
   **
  ***
 ****
10***
11*** (prefix repeated, skip)
120**
121** (prefix repeated, skip)
122** (prefix repeated, skip)
1230*
1231* (prefix repeated, skip)
1232* (prefix repeated, skip)
1233* (prefix repeated, skip)
12340
12341 (prefix repeated, skip)
12342
12343
12344 (prefix repeated, skip)
12345
and use N to minus the count we will get the answer.


class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int res=0;
        vector<int> digits;
        for (int i=N+1; i>0; i/=10) digits.push_back(i%10);
        reverse(digits.begin(), digits.end());
        
        int n=digits.size();
        for (int i=1; i<n; ++i) res+=9*perm(9, i-1);        
        
        unordered_set<int> st;
        for (int i=0; i<n; ++i) {
            for (int j=i==0?1:0; j<digits[i]; ++j) {
                if (st.find(j)==st.end()) {
                    res+=perm(9-i, n-i-1);
                }
            }
            if (st.find(digits[i])!=st.end()) break;
            st.insert(digits[i]);
        }
        return N-res;
    }
private:
    int perm(int m, int len) {
        int res=1;        
        for (int i=0; i<len; ++i) res*=m-i;
        return res;
    }
};

