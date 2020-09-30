69. Sqrt(x) Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 144973
Total Submissions: 528938
Difficulty: Easy
Contributor: LeetCode
Implement int sqrt(int x).

Compute and return the square root of x.

Subscribe to see which companies asked this question.

Hide Tags Binary Search Math
Hide Similar Problems (M) Pow(x, n) (E) Valid Perfect Square

1.
class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x, mid;

        while (l<r) {
            mid=l+(r-l)/2+1;
            if (mid==x/mid) return mid;
            else if (mid<x/mid) l=mid;
            else r=mid-1;
        }

        return l;
    }
};

