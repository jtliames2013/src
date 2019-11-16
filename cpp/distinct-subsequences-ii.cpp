940. Distinct Subsequences II
Hard

240

11

Favorite

Share
Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
Example 2:

Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
Example 3:

Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

 

Note:

S contains only lowercase letters.
1 <= S.length <= 2000

endswith[i] to count how many sub sequence that ends with ith character.

Now we have N = sum(endswith) different sub sequence,
add a new character c to each of them,
then we have N different sub sequence that ends with c.

class Solution {
public:
    int distinctSubseqII(string S) {
        long res=0, other=0;
        vector<long> endWith(26);
        for (auto c:S) {
            other=(res-endWith[c-'a']+mod)%mod;
            res=(res+other+1)%mod;
            endWith[c-'a']=(endWith[c-'a']+other+1)%mod;
        }
        return res;
    }
private:
    const int mod=1e9+7;
};

