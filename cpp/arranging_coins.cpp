441. Arranging Coins   QuestionEditorial Solution  My Submissions
Total Accepted: 4770 Total Submissions: 12895 Difficulty: Easy Contributors: Admin
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

Subscribe to see which companies asked this question

Hide Tags Binary Search Math

class Solution {
public:
    int arrangeCoins(int n) {
        long l=0, r=n;
        long mid;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (mid*(mid+1)/2<=n) l=mid;
            else r=mid-1;
        }
        return l;
    }
};

2.
class Solution {
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};

