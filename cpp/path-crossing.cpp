1496. Path Crossing
Easy

28

1

Add to List

Share
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.

 

Example 1:



Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:



Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}

class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> st;
        int row=0, col=0;
        st.insert({row, col});
        for (auto& p:path) {
            if (p=='N') row--;
            else if (p=='S') row++;
            else if (p=='E') col++;
            else if (p=='W') col--;
            if (st.find({row, col})!=st.end()) return true;
            st.insert({row, col});
        }
        return false;
    }
};
