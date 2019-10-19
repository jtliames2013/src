223. Rectangle Area Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 59384
Total Submissions: 183286
Difficulty: Medium
Contributor: LeetCode
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

Subscribe to see which companies asked this question.

Hide Tags Math

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long left=max(A, E);
        long right=min(C, G);
        long bottom=max(B, F);
        long top=min(D, H);
        long common=0;
        
        if (right>left && top>bottom) common=(right-left)*(top-bottom);
        return (long)(C-A)*(D-B)+(long)(G-E)*(H-F)-common;
    }
};
