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

1. range sum, time limit exceeded

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res=INT_MIN;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int area=matrix[i][j];
                if (i>0) area+=sum[i-1][j];
                if (j>0) area+=sum[i][j-1];
                if (i>0&&j>0) area-=sum[i-1][j-1];
                sum[i][j]=area;
                
                for (int r=0; r<=i; r++) {
                    for (int c=0; c<=j; c++) {
                        int rect=sum[i][j];
                        if (r>0) rect-=sum[r-1][j];
                        if (c>0) rect-=sum[i][c-1];
                        if (r>0&&c>0) rect+=sum[r-1][c-1];
                        if (rect<=k) res=max(res, rect);
                    }
                }
            }
        }
        
        return res;
    }
};

2.
题目可以通过降维转化为求解子问题：和不大于k的最大子数组，解法参考：https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k

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
        int res=INT_MIN;
        bool scanrow=true;
        if (m>n) {
            swap(m,n);
            scanrow=false;
        }

        for (int i=0; i<m; i++) {
			// sum up for each column into one row
            vector<int> sum(n, 0);
            for (int j=i; j>=0; j--) {
                set<int> st;
                int currSum=0;
                st.insert(currSum);
                
                for (int col=0; col<n; col++) {
                    sum[col]+=scanrow?matrix[j][col]:matrix[col][j];
                    currSum+=sum[col];
                    
                    auto iter=st.lower_bound(currSum-k);
                    if (iter!=st.end()) res=max(res, currSum-*iter);
                    st.insert(currSum);
                }
            }
        }

        return res;
    }
};
