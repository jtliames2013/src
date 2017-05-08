506. Relative Ranks Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 13019
Total Submissions: 27572
Difficulty: Easy
Contributors:
taylorty
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.

1. priority queue
class Solution {
public:
    class Compare {
    public:
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first<b.first;
        }
    };
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return vector<string>();
        vector<string> res(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for (int i=0; i<n; i++) pq.push({nums[i],i});
        int count=0;
        while (!pq.empty()) {
            pair<int,int> t=pq.top();
            pq.pop();
            count++;
            if (count==1) res[t.second]="Gold Medal";
            else if (count==2) res[t.second]="Silver Medal";
            else if (count==3) res[t.second]="Bronze Medal";
            else res[t.second]=to_string(count);
        }

        return res;
    }
};

2. sort
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return vector<string>();
        vector<string> res(n);
        vector<int> rank(n);
        for (int i=0; i<n; i++) rank[i]=i;
        sort(rank.begin(), rank.end(), [&](int a, int b) {return nums[a]>nums[b];});
        
        for (int i=0; i<n; i++) {
            if (i==0) res[rank[i]]="Gold Medal";
            else if (i==1) res[rank[i]]="Silver Medal";
            else if (i==2) res[rank[i]]="Bronze Medal";
            else res[rank[i]]=to_string(i+1);
        }

        return res;
    }
};

