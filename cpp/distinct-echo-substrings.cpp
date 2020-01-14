1316. Distinct Echo Substrings
Hard

25

67

Add to List

Share
Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).

 

Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
Example 2:

Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
 

Constraints:

1 <= text.length <= 2000
text has only lowercase English letters.

https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        unordered_set<long> st;
        vector<long> hash(n+1), pow(n+1);
        pow[0]=1;
        for (int i=1; i<=n; ++i) {
            hash[i]=(hash[i-1]*base+text[i-1])%mod;
            pow[i]=pow[i-1]*base%mod;
        }
        for (int l=2; l<=n; l+=2) {
            for (int i=0; i+l<=n; ++i) {                
                long left=getHash(hash, pow, i, i+l/2), right=getHash(hash, pow, i+l/2, i+l);
                if (left==right) st.insert(left);
            }
        }
        return st.size();
    }
private:
    long getHash(vector<long>& hash, vector<long>& pow, int l, int r) {
        return (hash[r]-hash[l]*pow[r-l]%mod+mod)%mod;
    }
    const long base=256;
    const long mod=1e9+7;
};
