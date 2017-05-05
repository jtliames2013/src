451. Sort Characters By Frequency Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 25242
Total Submissions: 49839
Difficulty: Medium
Contributors:
stickypens
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
Subscribe to see which companies asked this question.

Hide Tags Hash Table Heap
Hide Similar Problems (M) Top K Frequent Elements

class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> count;
        for (auto c:s) count[c]++;
        vector<string> bucket(s.size()+1);
        for (auto c:count) bucket[c.second].append(c.second, c.first);
        
        for (int i=bucket.size()-1; i>=0; i--) {
            if (!bucket[i].empty()) {
                res+=bucket[i];
            }
        }

        return res;
    }
};

2.
class Solution {
public:
    class Compare {
    public:
        bool operator()(pair<char,int>& a, pair<char,int>& b) {
            return a.second<b.second;
        }
    };
    
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> count;
        for (auto c:s) count[c]++;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for (auto c:count) pq.push({c.first, c.second});
        
        while (!pq.empty()) {
            pair<char,int> t=pq.top();
            pq.pop();
            res.append(t.second, t.first);
        }

        return res;
    }
};

