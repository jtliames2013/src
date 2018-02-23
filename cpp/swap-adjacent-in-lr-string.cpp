777. Swap Adjacent in LR String
DescriptionHintsSubmissionsDiscussSolution
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.

// L and R should be in the same order.
// L can only move left so L in start can't have smaller index than L in end
// R can only move right so R in start can't have larger index than R in end 
class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0, j=0, n=start.size();
        for (; i<n && j<n; i++, j++) {
            while (i<n && start[i]=='X') i++;
            while (j<n && end[j]=='X') j++;
            if (i==n && j==n) break;
            if (i==n || j==n || start[i]!=end[j]) return false;
            if (start[i]=='L' && i<j) return false;
            if (start[i]=='R' && i>j) return false;
        }
        return true;
    }
};
