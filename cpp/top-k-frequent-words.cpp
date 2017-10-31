692. Top K Frequent Words
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> mp;
        for (auto& w:words) mp[w]++;
        auto comp=[](pair<string,int>& a, pair<string,int>& b) { return a.second>b.second || (a.second==b.second && a.first<b.first); };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> pq(comp);
        for (auto iter:mp) {
            if (pq.size()<k) pq.push({iter.first, iter.second});
            else {
                if (iter.second>pq.top().second || (iter.second==pq.top().second && iter.first<pq.top().first)) {
                    pq.pop();
                    pq.push({iter.first, iter.second});
                }
            }
        }
        
        while (!pq.empty()) {            
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

