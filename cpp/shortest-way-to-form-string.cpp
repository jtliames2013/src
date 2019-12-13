1055. Shortest Way to Form String
Medium

244

17

Favorite

Share
From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
 

Constraints:

Both the source and target strings consist of only lowercase English letters from "a"-"z".
The lengths of source and target string are between 1 and 1000.

Google
|
13

1. subsequence match
class Solution {
public:
    int shortestWay(string source, string target) {
        int res=0, m=source.size(), n=target.size();
        for (int i=0; i<n; ) {
            int k=i;
            for (int j=0; j<m; ++j) {
                if (source[j]==target[k]) k++;
            }
            if (k==i) return -1;
            i=k;
            res++;
        }
        
        return res;
    }
};

2. binary search
class Solution {
public:
    int shortestWay(string source, string target) {
        int res=1, m=source.size(), n=target.size();
        vector<vector<int>> index(26);
        for (int i=0; i<m; ++i) index[source[i]-'a'].push_back(i);
        
        for (int i=0, j=0; i<n; ) {            
            vector<int>& v=index[target[i]-'a'];
            auto iter=lower_bound(v.begin(), v.end(), j);
            if (iter==v.end()) {
                if (j==0) return -1;
                j=0;
                res++;
            } else {
                j=*iter+1;
                i++;
            }
        }
        
        return res;
    }
};


