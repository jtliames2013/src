302. Smallest Rectangle Enclosing Black Pixels
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.

Hide Company Tags Google
Hide Tags Binary Search


// NOTE: binary search row and column separately to find the boundary row/column with black pixel
// Search dereasingly and increasingly are different. In decrease case, search the line with black pixel.
// In increase case, search the line next to black pixel line. So need handle special case when all lines 
// in the increasing direction have black pixel.

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int searchRow(vector<vector<char>>& image, int rowmin, int rowmax, int colmin, int colmax, bool decrease) {
        int l=rowmin, r=rowmax;
        int mid;
        while (l<r) {
            mid=(l+r)/2;
            bool hasBlack=false;
            for (int i=colmin; i<=colmax; i++) {
                if (image[mid][i]=='1') { hasBlack=true; break; }
            }
            if (decrease) {
                if (hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            } else {
                if (!hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
        }
        
        // special case when rowmax has black pixel
        for (int i=colmin; i<=colmax; i++) {
            if (image[rowmax][i]=='1' && decrease==false) return rowmax+1;
        }

        return r;
    }

    int searchCol(vector<vector<char>>& image, int rowmin, int rowmax, int colmin, int colmax, bool decrease) {
        int l=colmin, r=colmax;
        int mid;
        while (l<r) {
            mid=(l+r)/2;
            bool hasBlack=false;
            for (int i=rowmin; i<=rowmax; i++) {
                if (image[i][mid]=='1') { hasBlack=true; break; }
            }
            if (decrease) {
                if (hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            } else {
                if (!hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
        }

        // special case when colmax has black pixel
        for (int i=rowmin; i<=rowmax; i++) {
            if (image[i][colmax]=='1' && decrease==false) return colmax+1;
        }
        return r;
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        int row = image.size();
        if (row==0) return 0;
        int col = image[0].size();

        // left is the leftmost line with black pixel
        int left=searchRow(image, 0, x, 0, col-1, true);
        // right is the rigtmost line without black pixel
        int right=searchRow(image, x, row-1, 0, col-1, false);
        int top=searchCol(image, left, right-1, 0, y, true);
        int bottom=searchCol(image, left, right-1, y, col-1, false);

        return (right-left)*(bottom-top);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    vector<vector<char>> image(3, vector<char>(4, '0'));
    image[0][2]=image[1][1]=image[1][2]=image[2][1]='1';
    Solution s;
    s.minArea(image, 0, 2);
	return 0;
}
