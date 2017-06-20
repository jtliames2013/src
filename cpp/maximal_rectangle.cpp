85. Maximal Rectangle  QuestionEditorial Solution  My Submissions
Total Accepted: 45588 Total Submissions: 189955 Difficulty: Hard
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Hide Company Tags Facebook
Hide Tags Array Hash Table Stack Dynamic Programming
Hide Similar Problems (H) Largest Rectangle in Histogram (M) Maximal Square


优化就是先预处理成保存成，当前点向上都是1的最高的高度，就变成每一行都是一个直方图，之后用O（n）的直方图求最大面积去算

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

