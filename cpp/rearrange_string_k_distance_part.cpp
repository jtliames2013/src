358. Rearrange String k Distance Apart 
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Hash Table Heap Greedy

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

