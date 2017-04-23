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
        int left=max(A, E);
        int right=min(C, G);
        int bottom=max(B, F);
        int top=min(D, H);
        int common=0;
        
        if (right>left && top>bottom) {
            common=(right-left)*(top-bottom);
        }
        
        return (C-A)*(D-B)+(G-E)*(H-F)-common;
    }
};
