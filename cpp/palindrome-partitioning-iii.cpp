1278. Palindrome Partitioning III
Hard

71

2

Favorite

Share
You are given a string s containing lowercase letters and an integer k. You need to :

First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
Return the minimal number of characters that you need to change to divide the string.

 

Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
Example 2:

Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
Example 3:

Input: s = "leetcode", k = 8
Output: 0
 

Constraints:

1 <= k <= s.length <= 100.
s only contains lowercase English letters.

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n=s.size();
        unordered_map<int, int> mp;
        return dfs(mp, s, 0, n, k);
    }
private:
    int dfs(unordered_map<int, int>& mp, string& s, int start, int n, int k) {
        int key=((start<<16) | k);
        if (mp.find(key)!=mp.end()) return mp[key];
        int res=INT_MAX;
        if (n-start==k) return 0;
        
        if (k==1) {
            res=cost(s, start, n-1);
        } else {
            for (int j=start+1; j<=n-k+1; ++j) {
                res=min(res, cost(s, start, j-1)+dfs(mp, s, j, n, k-1));
            }
        }
        
        mp[key]=res;
        return res;
    }
    
    int cost(string& s, int l, int r) {
        int res=0;
        while (l<r) {
            if (s[l]!=s[r]) res++;
            l++;
            r--;
        }
        return res;
    }
};

