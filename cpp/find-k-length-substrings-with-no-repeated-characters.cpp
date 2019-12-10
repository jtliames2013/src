1100. Find K-Length Substrings With No Repeated Characters
Medium

66

5

Favorite

Share
Given a string S, return the number of substrings of length K with no repeated characters.

 

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.
 

Note:

1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4

Amazon
|
2

1.
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int res=0, n=S.size();
        unordered_map<char, int> mp;
        for (int i=0; i<n; ++i) {
            mp[S[i]]++;
            if (i>=K) {
                mp[S[i-K]]--;
                if (mp[S[i-K]]==0) mp.erase(S[i-K]);
            }
            if (i>=K-1) {
                if (mp.size()==K) res++;
            }
            
        }
        return res;
    }
};

2.
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int res=0, n=S.size();
        unordered_set<char> st;
        for (int l=0, r=0; r<n; ++r) {
            while (st.find(S[r])!=st.end()) st.erase(S[l++]);
            st.insert(S[r]);
            if (r-l+1>=K) res++;
        }
        return res;
    }
};

