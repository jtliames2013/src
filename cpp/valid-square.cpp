593. Valid Square
DescriptionHintsSubmissionsSolutions
Total Accepted: 2876
Total Submissions: 7580
Difficulty: Medium
Contributors:
fallcreek
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
Subscribe to see which companies asked this question.

Hide Tags Math

class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st({dist(p1,p2), dist(p1,p3), dist(p1,p4), dist(p2,p3), dist(p2,p4), dist(p3,p4)});
        return st.size()==2 && st.count(0)==0;
    }
};

