959. Regions Cut By Slashes
Medium

379

85

Favorite

Share
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {                
        n=grid.size();
        count=n*n*4;
        vector<int> root(n*n*4);
        for (int i=0; i<n*n*4; ++i) root[i]=i;
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                // top 0, right 1, bottom 2, left 3
                if (i>0) uni(root, index(i-1, j, 2), index(i, j, 0));
                if (j>0) uni(root, index(i, j-1, 1), index(i, j, 3));
                if (grid[i][j]!='/') {
                    uni(root, index(i, j, 0), index(i, j, 1));
                    uni(root, index(i, j, 2), index(i, j, 3));
                }
                if (grid[i][j]!='\\') {
                    uni(root, index(i, j, 0), index(i, j, 3));
                    uni(root, index(i, j, 1), index(i, j, 2));
                }
            }
        }
        
        return count;
    }
private:
    int index(int i, int j, int k) {
        return (i*n+j)*4+k;
    }
    
    int find(vector<int>& root, int i) {
        while (i!=root[i]) i=root[i];
        return i;
    }
    
    void uni(vector<int>& root, int i, int j) {
        i=find(root, i);
        j=find(root, j);
        if (i!=j) {
            root[i]=j;
            count--;
        }
    }
    
    int count;
    int n;
};
