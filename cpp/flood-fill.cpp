733. Flood Fill
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        if (m==0) return image;
        int n=image[0].size();
        if (n==0) return image;
        int oldColor=image[sr][sc];
        if (oldColor==newColor) return image;
        dfs(image, sr, sc, m, n, oldColor, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, int row, int col, int m, int n, int oldColor, int newColor) {
        image[row][col]=newColor;
        for (int k=0; k<4; ++k) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==oldColor) {
                dfs(image, nr, nc, m, n, oldColor, newColor);
            }
        }
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1},{0,1}};
};
