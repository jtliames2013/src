374. Guess Number Higher or Lower   QuestionEditorial Solution  My Submissions
Total Accepted: 25741 Total Submissions: 79083 Difficulty: Easy Contributors: Admin
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:
n = 10, I pick 6.

Return 6.
Subscribe to see which companies asked this question

Hide Tags Binary Search
Hide Similar Problems (E) First Bad Version (M) Guess Number Higher or Lower II

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l=1, r=n, mid;
        while (l<=n) {
            mid=l+(r-l)/2;
            int res=guess(mid);
            if (res==0) return mid;
            else if (res<0) r=mid-1;
            else l=mid+1;
        }
    }
};

