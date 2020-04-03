621. Task Scheduler
DescriptionHintsSubmissionsSolutions
Total Accepted: 1060
Total Submissions: 2886
Difficulty: Medium
Contributors:
fallcreek
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
Subscribe to see which companies asked this question.

Hide Tags Array Greedy Queue
Hide Similar Problems (H) Rearrange String k Distance Apart

1. priority queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (auto t:tasks) mp[t]++;
        priority_queue<int> pq;
        for(auto iter:mp) pq.push(iter.second);
        int cycle=n+1, res=0;
        while (!pq.empty()) {
            vector<int> cnt;
            for (int i=0; i<cycle; ++i) {
                if (pq.empty()) break;
                cnt.push_back(pq.top());
                pq.pop();
            }
            
            for (auto c:cnt) {
                if (c>1) pq.push(c-1);
            }
            
            res+=pq.empty()?cnt.size():cycle;
        }
        return res;
    }
};

2. math
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (auto t:tasks) count[t-'A']++;
        int maxVal=INT_MIN, maxCnt=0;
        for (int i=0; i<26; i++) {
            if (count[i]>maxVal) {
                maxVal=count[i];
                maxCnt=1;
            } else if (count[i]==maxVal) {
                maxCnt++;
            }
        }

        return max((maxVal-1)*(n+1)+maxCnt, (int)tasks.size());
    }
};

