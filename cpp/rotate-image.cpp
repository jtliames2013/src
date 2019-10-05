48. Rotate Image  QuestionEditorial Solution  My Submissions
Total Accepted: 76768 Total Submissions: 214657 Difficulty: Medium
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Hide Company Tags Amazon Microsoft Apple
Hide Tags Array

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0; i<n/2; i++) {
            for (int j=i; j<n-i-1; j++) {
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=tmp;
            }
        }
    }
};

2.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        reverse(matrix.begin(), matrix.end());
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) swap(matrix[i][j], matrix[j][i]);
        }
    }
};
