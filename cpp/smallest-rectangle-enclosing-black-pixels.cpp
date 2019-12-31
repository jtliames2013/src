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

class Solution {
public:
    int searchRow(vector<vector<char>>& image, int rowmin, int rowmax, int colmin, int colmax, bool decrease) {
        int l=rowmin, r=rowmax, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            bool hasBlack=false;
            for (int i=colmin; i<=colmax; i++) {
                if (image[mid][i]=='1') {
                    hasBlack=true;
                    break;
                }
            }
            
            if (decrease) {
                if (hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            } else {
                if (hasBlack) {
                    l=mid+1;
                } else {
                    r=mid;
                }
            }                        
        }
        
        return l;
    }
    
    int searchCol(vector<vector<char>>& image, int rowmin, int rowmax, int colmin, int colmax, bool decrease) {
        int l=colmin, r=colmax, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            bool hasBlack=false;
            for (int i=rowmin; i<=rowmax; i++) {
                if (image[i][mid]=='1') {
                    hasBlack=true;
                    break;
                }
            }
            
            if (decrease) {
                if (hasBlack) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            } else {
                if (hasBlack) {
                    l=mid+1;
                } else {
                    r=mid;
                }
            }                        
        }
        
        return l;        
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m=image.size();
        if (m==0) return 0;
        int n=image[0].size();
        if (n==0) return 0;
        
        int left=searchRow(image, 0, x, 0, n-1, true);
        int right=searchRow(image, x+1, m, 0, n-1, false);
        int top=searchCol(image, left, right-1, 0, y, true);
        int bottom=searchCol(image, left, right-1, y+1, n, false);
        return (right-left)*(bottom-top);
    }
};

