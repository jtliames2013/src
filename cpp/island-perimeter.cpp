463. Island Perimeter Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 36715
Total Submissions: 64552
Difficulty: Easy
Contributors:
amankaraj
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

Subscribe to see which companies asked this question.

Hide Tags Hash Table

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        int islands=0, neighbors=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    islands++;
                    if (i>0 && grid[i-1][j]==1) neighbors++;
                    if (j>0 && grid[i][j-1]==1) neighbors++;
                }
            }
        }
        return islands*4-neighbors*2;
    }
};

