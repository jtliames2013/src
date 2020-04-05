1405. Longest Happy String
Medium

17

23

Add to List

Share
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        auto comp=[](pair<char, int>& a,  pair<char, int>& b){ return a.second<b.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        if (a>0) pq.push({'a', a});
        if (b>0) pq.push({'b', b});
        if (c>0) pq.push({'c', c});
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (res.empty() || res.back()!=t.first) {
                int cnt=min(2, t.second);
                res.append(cnt, t.first);
                t.second-=cnt;
                if (t.second>0) pq.push({t.first, t.second});
            } else if (!pq.empty()) {
                auto t2=pq.top();
                pq.pop();
                res.append(1, t2.first);
                t2.second--;
                if (t2.second>0) pq.push({t2.first, t2.second});
                pq.push(t);
            } else {
                break;
            }
        }

        return res;
    }
};

