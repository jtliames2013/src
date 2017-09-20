391. Perfect Rectangle Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8637
Total Submissions: 33685
Difficulty: Hard
Contributor: LeetCode
Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
Subscribe to see which companies asked this question.


The right answer must satisfy two conditions:

1. the boudning rectangle area should be equal to the sum of individual rectangles
2. count of all the points should be even, and that of all the four corner points should be one

class Solution {
public:
    struct myhash
    {
        size_t operator()(const pair<int, int>& p) const
        {
            return (hash<int>{}(p.first)) ^ (hash<int>{}(p.second)<<1);
        }
    };
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return false;
        int bottom=INT_MAX, left=INT_MAX, top=INT_MIN, right=INT_MIN;
        int area=0;
        unordered_set<pair<int,int>, myhash> st;
        
        for (auto rect:rectangles) {
            bottom=min(bottom, rect[0]);
            left=min(left, rect[1]);
            top=max(top, rect[2]);
            right=max(right, rect[3]);
            area+=(rect[2]-rect[0])*(rect[3]-rect[1]);
            
            pair<int,int> p1 = {rect[0], rect[1]};
            pair<int,int> p2 = {rect[0], rect[3]};
            pair<int,int> p3 = {rect[2], rect[3]};
            pair<int,int> p4 = {rect[2], rect[1]};
            
            if (st.find(p1)==st.end()) st.insert(p1);
            else st.erase(p1);
            
            if (st.find(p2)==st.end()) st.insert(p2);
            else st.erase(p2);

            if (st.find(p3)==st.end()) st.insert(p3);
            else st.erase(p3);

            if (st.find(p4)==st.end()) st.insert(p4);
            else st.erase(p4);
        }
        
        if (st.find({bottom, left})==st.end() ||
            st.find({bottom, right})==st.end() ||
            st.find({top, right})==st.end() ||
            st.find({top, left})==st.end() ||
            st.size()!=4) {
                return false;
            }
            
        return area==(top-bottom)*(right-left);
    }
};

