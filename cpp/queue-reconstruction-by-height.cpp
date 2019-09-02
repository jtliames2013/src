406. Queue Reconstruction by Height Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 21268
Total Submissions: 38841
Difficulty: Medium
Contributor: LeetCode
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
Subscribe to see which companies asked this question.

Hide Tags Greedy
Hide Similar Problems (H) Count of Smaller Numbers After Self

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){ return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]); });
        
        for (auto p:people) res.insert(res.begin()+p[1], p);
        return res;
    }
};
