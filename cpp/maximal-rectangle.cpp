85. Maximal Rectangle  QuestionEditorial Solution  My Submissions
Total Accepted: 45588 Total Submissions: 189955 Difficulty: Hard
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Hide Company Tags Facebook
Hide Tags Array Hash Table Stack Dynamic Programming
Hide Similar Problems (H) Largest Rectangle in Histogram (M) Maximal Square


优化就是先预处理成保存成，当前点向上都是1的最高的高度，就变成每一行都是一个直方图，之后用O（n）的直方图求最大面积去算

The DP solution proceeds row by row, starting from the first row. Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).

All the 3 variables left, right, and height can be determined by the information from previous row, and also information from the current row. So it can be regarded as a DP solution. The transition equations are:

left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row

right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row

height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';

height(i,j) = 0, if matrix[i][j]=='0'

 * height[i] record the current number of countinous '1' in column i;
 * left[i] record the left most index j which satisfies that for any index k from j to  i, height[k] >= height[i];
 * right[i] record the right most index j which satifies that for any index k from i to  j, height[k] >= height[i];

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res=0;
        vector<int> left(n), right(n, n), height(n);
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int curr=0;
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]=='1') left[j]=max(left[j], curr);
                else {
                    left[j]=0;
                    curr=j+1;
                }
            }
            curr=n;
            for (int j=n-1; j>=0; --j) {
                if (matrix[i][j]=='1') right[j]=min(right[j], curr);
                else {
                    right[j]=n;
                    curr=j;
                }
            }
            
            for (int j=0; j<n; ++j) res=max(res, (right[j]-left[j])*height[j]);
        }
        return res;
    }
};

2.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res=0;
        vector<int> height(n+1);
        for (int i=0; i<m; i++) {
            stack<int> idx;
            for (int j=0; j<=n; j++) {
                if (j<n) {
                    if (matrix[i][j]=='1') height[j]+=1;
                    else height[j]=0;
                }        
                while (!idx.empty() && height[idx.top()]>=height[j]) {
                    int curr=idx.top();
                    idx.pop();
                    res=max(res, height[curr]*(idx.empty()?j:(j-idx.top()-1)));
                }
                
                idx.push(j);
            }
        }
        
        return res;
    }
};

