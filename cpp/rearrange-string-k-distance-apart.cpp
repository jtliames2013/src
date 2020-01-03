358. Rearrange String k Distance Apart
Hard

356

16

Add to List

Share
Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:

Input: s = "aabbcc", k = 3
Output: "abcabc" 
Explanation: The same letters are at least distance 3 from each other.
Example 2:

Input: s = "aaabc", k = 3
Output: "" 
Explanation: It is not possible to rearrange the string.
Example 3:

Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least distance 2 from each other.

Facebook
|
2

Amazon
|
2

Google
|
5

The greedy algorithm is that in each step, select the char with highest remaining count if possible.

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k==0) return s;
        string res;
        int n=s.size();
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto& iter:mp) pq.push({iter.second, iter.first});
        
        while (!pq.empty()) {            
            if (pq.size()<k && pq.top().first>1) return "";
            vector<pair<int,char>> next;
            int len=pq.top().first==1?pq.size():k;
            for (int i=0; i<len; i++) {
                auto t=pq.top();
                pq.pop();
                res.push_back(t.second);
                t.first--;
                if (t.first>0) next.push_back(t);
            }
            for (auto& i:next) pq.push(i);
        }
        
        return res;
    }
};

2.
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k==0) return s;
        string res;
        int n=s.size();
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto& iter:mp) pq.push({iter.second, iter.first});
        
        while (!pq.empty()) {
            int len=min(k, n);
            if (pq.size()<len) return "";
            vector<pair<int,char>> next;
            for (int i=0; i<len; i++) {
                auto t=pq.top();
                pq.pop();
                res.push_back(t.second);
                t.first--;
                if (t.first>0) next.push_back(t);
            }
            n-=len;
            for (auto& i:next) pq.push(i);
        }
        
        return res;
    }
};

