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

Google
|
2

// NOTE: binary search row and column separately to find the boundary row/column with black pixel
// Search dereasingly and increasingly are different. In decrease case, search the line with black pixel.
// In increase case, search the line next to black pixel line. So need handle special case when all lines 
// in the increasing direction have black pixel.

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m=image.size();
        if (m==0) return 0;
        int n=image[0].size();
        if (n==0) return 0;

        int top=searchRow(image, 0, x, 0, n-1, true);
        int bottom=searchRow(image, x, m-1, 0, n-1, false);
        int left=searchCol(image, 0, m-1, 0, y, true);
        int right=searchCol(image, 0, m-1, y, n-1, false);
        return (bottom-top+1)*(right-left+1);
    }
private:
    int searchRow(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax, bool blackOnRight) {
        int l=rowMin, r=rowMax, mid;
        while (l<r) {
            mid=l+(r-l)/2+(blackOnRight?0:1);
            bool hasBlack=false;
            for (int i=colMin; i<=colMax; ++i) {
                if (image[mid][i]=='1') {
                    hasBlack=true;
                    break;
                }
            }
            
            if (blackOnRight) {
                if (hasBlack) r=mid;
                else l=mid+1;
            } else {
                if (hasBlack) l=mid;
                else r=mid-1;
            }
        }
        return l;
    }
    
    int searchCol(vector<vector<char>>& image, int rowMin, int rowMax, int colMin, int colMax, bool blackOnRight) {
        int l=colMin, r=colMax, mid;
        while (l<r) {
            mid=l+(r-l)/2+(blackOnRight?0:1);
            bool hasBlack=false;
            for (int i=rowMin; i<=rowMax; ++i) {
                if (image[i][mid]=='1') {
                    hasBlack=true;
                    break;
                }
            }
            
            if (blackOnRight) {
                if (hasBlack) r=mid;
                else l=mid+1;
            } else {
                if (hasBlack) l=mid;
                else r=mid-1;
            }
        }
        return l;
    }
};

