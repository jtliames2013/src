363. Max Sum of Rectangle No Larger Than K 
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Binary Search Dynamic Programming Queue

题目可以通过降维转化为求解子问题：和不大于k的最大子数组，解法参考：https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k

First thing to note is that sum of subarray (i,j](i,j] is just the sum of the first jj elements less the sum of the first ii elements. Store these cumulative sums in the array cum. Then the problem reduces to finding  i,ji,j such that i<ji<j and cum[j]−cum[i]cum[j]−cum[i] is as close to kk but lower than it.

To solve this, scan from left to right. Put the cum[i]cum[i] values that you have encountered till now into a set. When you are processing cum[j]cum[j] what you need to retrieve from the set is the smallest number in the set such which is bigger than cum[j]−kcum[j]−k. This lookup can be done in O(logn)O(log⁡n) using upper_bound. Hence the overall complexity is O(nlog(n))O(nlog⁡(n)).

Here is a c++ function that does the job, assuming that K>0 and that the empty interval with sum zero is a valid answer. The code can be tweaked easily to take care of more general cases and to return the interval itself.

int best_cumulative_sum(int ar[],int N,int K)
{
    set<int> cumset;
    cumset.insert(0);
    int best=0,cum=0;
    for(int i=0;i<N;i++)
    {
        cum+=ar[i];
        set<int>::iterator sit=cumset.upper_bound(cum-K);
        if(sit!=cumset.end())best=max(best,cum-*sit);
        cumset.insert(cum);
    }
    return best;
}

首先枚举列的起止范围x, y，子矩阵matrix[][x..y]可以通过部分和数组sums进行表示：
sums[i] = Σ(matrix[i][x..y])
接下来求解sums数组中和不大于k的最大子数组的和。
如果矩阵的列数远大于行数，则将枚举列变更为枚举行即可。

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        bool binarySearchInRow=true;
        if (m>n) {
            swap(m,n);
            binarySearchInRow=false;
        }
        
        int res=INT_MIN;
        for (int i=0; i<m; i++) {
            vector<int> sumRow(n);    
            for (int j=i; j>=0; j--) {
                int sumCol=0;
                set<int> st;
                st.insert(sumCol);
                
                for (int col=0; col<n; col++) {
                    sumRow[col]+=binarySearchInRow?matrix[j][col]:matrix[col][j];
                    sumCol+=sumRow[col];
                    
                    auto iter=st.lower_bound(sumCol-k);
                    if (iter!=st.end()) {
                        res=max(res, sumCol-*iter);
                    }
                    st.insert(sumCol);
                }
            }
        }
        return res;
    }
};

