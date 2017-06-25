267. Palindrome Permutation II
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations II (E) Palindrome Permutation

1. map
class Solution {
public:
    void dfs(vector<string>& res, unordered_map<char,int>& mp, string& str, int start, int end, char oddch) {
        if (start>=end) {
            if (start==end) str[start]=oddch;
            res.push_back(str);
            return;
        }
        
        for (auto& iter:mp) {
            if (iter.second>=2) {
                iter.second-=2;
                str[start]=str[end]=iter.first;
                dfs(res, mp, str, start+1, end-1, oddch);
                iter.second+=2;
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int n=s.size();
        if (n==0) return res;
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        int odd=0;
        char oddch;
        for (auto& iter:mp) {
            if (iter.second%2==1) {
                odd++;
                oddch=iter.first;
            }
            if (odd>1) return res;
        }
        
        string str(n, 0);
        dfs(res, mp, str, 0, n-1, oddch);
        
        return res;
    }
};

2. array
class Solution {
public:
    void dfs(vector<string>& res, int count[], string& str, int start, int end, char oddch) {
        if (start>=end) {
            if (start==end) str[start]=oddch;
            res.push_back(str);
            return;
        }
        
        for (int i=0; i<256; i++) {
            if (count[i]>=2) {
                count[i]-=2;
                str[start]=str[end]=i;
                dfs(res, count, str, start+1, end-1, oddch);
                count[i]+=2;
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int n=s.size();
        if (n==0) return res;
        int count[256]={0};
        for (auto c:s) count[c]++;
        int odd=0;
        char oddch;
        for (int i=0; i<256; i++) {
            if (count[i]%2==1) {
                odd++;
                oddch=i;
            }
            if (odd>1) return res;
        }
        
        string str(n, 0);
        dfs(res, count, str, 0, n-1, oddch);
        
        return res;
    }
};

