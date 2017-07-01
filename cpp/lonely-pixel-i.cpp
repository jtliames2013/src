531. Lonely Pixel I
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m=picture.size();
        if (m==0) return 0;
        int n=picture[0].size();
        if (n==0) return 0;
        vector<int> rowCnt(m), colCnt(n);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (picture[i][j]=='B') {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (picture[i][j]=='B' && rowCnt[i]==1 && colCnt[j]==1) res++;
            }
        }
        return res;
    }
};

