1209. Remove All Adjacent Duplicates in String II
Medium

124

4

Favorite

Share
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.

1. stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        vector<pair<char,int>> stk;
        for (auto c:s) {
            if (stk.empty() || stk.back().first!=c) {
                stk.push_back({c, 1});
            } else {
                stk.back().second++;
                if (stk.back().second==k) stk.pop_back();
            }
        }
        for (auto& p:stk) {
            res.append(p.second, p.first);
        }
        return res;
    }
};

2. two pointers
class Solution {
public:
    string removeDuplicates(string s, int k) {        
        int n=s.size(), end=0, i=0;
        vector<int> count(n);
        for (; i<n; ++i, ++end) {
            s[end]=s[i];
            count[end]=(end>0 && s[end-1]==s[end])?count[end-1]+1:1;
            if (count[end]==k) end-=k;
        }
        
        return s.substr(0, end);
    }
};
