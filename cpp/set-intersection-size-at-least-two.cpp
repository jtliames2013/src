759. Set Intersection Size At Least Two
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has size at least 2.

Example 1:
Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
Output: 3
Explanation:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.
Example 2:
Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
Output: 5
Explanation:
An example of a minimum sized set is {1, 2, 3, 4, 5}.
Note:

intervals will have length in range [1, 3000].
intervals[i] will have length 2, representing some integer interval.
intervals[i][j] will be an integer in [0, 10^8].

Intuition

Let's try to solve a simpler problem: what is the answer when the set intersection size is at least one?

Sort the points. Take the last interval [s, e], which point on this interval will be in S? Since every other interval has start point <= s, it is strictly better to choose s as the start. So we can repeatedly take s in our set S and remove all intervals containing s.

We will try to extend this solution to the case when we want an intersection of size two.

Algorithm

For each interval, we will perform the algorithm described above, storing a todo multiplicity which starts at 2. As we identify points in S, we will subtract from these multiplicities as appropriate.

One case that is important to handle is the following: [[1, 2], [2, 3], [2, 4], [4, 5]]. If we put 4, 5 in S, then we put 2 in S, when handling [2, 3] we need to put 3 in S, not 2 which was already put.

We can handle this case succinctly by sorting intervals [s, e] by s ascending, then e descending. This makes it so that any interval encountered with the same s has the lowest possible e, and so it has the highest multiplicity. When at interval [s, e] and choosing points to be included into S, it will always be the case that the start of the interval (either s or s, s+1) will be unused.

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]); });
        int res=0, n=intervals.size();
        vector<int> todo(n, 2);
        while (n-- > 0) {
            int s = intervals[n][0];
            int e = intervals[n][1];
            int m = todo[n];
            for (int p=s; p<s+m; ++p) {
                for (int i=0; i<=n; ++i) {
                    if (todo[i]>0 && p<=intervals[i][1]) todo[i]--;
                }
                res++;
            }
        }
        return res;        
    }
};
