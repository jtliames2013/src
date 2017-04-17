50. Pow(x, n) Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 142949
Total Submissions: 535449
Difficulty: Medium
Contributor: LeetCode
Implement pow(x, n).

Subscribe to see which companies asked this question.

Hide Tags Binary Search Math
Hide Similar Problems (E) Sqrt(x) (M) Super Pow

class Solution {
public:
	double powPositive(double x, long long n) {
		if (n==0) return 1;
		double res=powPositive(x, n/2);
		res *= res;
		if (n%2==1) res *= x;
		return res;
	}

	double myPow(double x, int n) {
		if (n>=0) {
			return powPositive(x, (long long)n);
		} else {
			return 1/powPositive(x,-(long long)n);
		}
    }
};

