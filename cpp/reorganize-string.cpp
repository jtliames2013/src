767. Reorganize String
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].

class Solution {
public:
    string reorganizeString(string S) {
        string res;
        unordered_map<char,int> mp;
        for (auto c:S) mp[c]++;
        
        for (auto iter:mp) {
            if (iter.second>(S.size()+1)/2) return res;
        }
        
        auto comp=[](pair<char,int>& a, pair<char,int>& b){ return a.second<b.second; };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> pq(comp);
        for (auto iter:mp) pq.push({iter.first, iter.second});
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            if (!res.empty() && t.first==res.back()) {
                auto n=pq.top();
                pq.pop();
                res+=n.first;
                if (n.second>1) pq.push({n.first, n.second-1});
            }
            res+=t.first;
            if (t.second>1) pq.push({t.first, t.second-1});
        }
        
        return res;
    }

};
