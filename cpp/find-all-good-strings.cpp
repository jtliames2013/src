1397. Find All Good Strings
Hard

13

13

Add to List

Share
Given the strings s1 and s2 of size n, and the string evil. Return the number of good strings.

A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:

Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
Output: 51 
Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
Example 2:

Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
Output: 0 
Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
Example 3:

Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
Output: 2
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 500
1 <= evil.length <= 50
All strings consist of lowercase English letters.

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> memo(1<<17, -1);
        vector<int> p=precompute(evil);
        return dfs(s1, s2, evil, n, memo, p, 0, 0, 1, 1);
    }
private:
    int dfs(string& s1, string& s2, string& evil, int n, vector<int>& memo, vector<int>& p, int sIdx, int eIdx, int leftBound, int rightBound) {
        if (eIdx==evil.size()) return 0;
        if (sIdx==n) return 1;
        int key=getKey(sIdx, eIdx, leftBound, rightBound);
        if (memo[key]!=-1) return memo[key];
        int res=0;
        char from=leftBound?s1[sIdx]:'a';
        char to=rightBound?s2[sIdx]:'z';
        for (char c=from; c<=to; ++c) {
            int j=eIdx;
            while (j>0 && evil[j]!=c) j=p[j-1];
            if (c==evil[j]) j++;
            res+=dfs(s1, s2, evil, n, memo, p, sIdx+1, j, leftBound && (c==from), rightBound && (c==to));
            res%=mod;
        }
        
        memo[key]=res;
        return memo[key];
    }
    
    int getKey(int i, int j, int l, int r) {
        return (i<<8) | (j<<2) | (l<<1) | r;
    }
    
    vector<int> precompute(string& s) {
        int n=s.size();
        vector<int> res(n);
        for (int i=1, j=0; i<n; ++i) {
            while (j>0 && s[i]!=s[j]) j=res[j-1];
            if (s[i]==s[j]) res[i]=++j;
        }
        return res;
    }
    const int mod=1e9+7;
};

