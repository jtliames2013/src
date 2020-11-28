1654. Minimum Jumps to Reach Home
Medium

110

22

Add to List

Share
A certain bug's home is on the x-axis at position x. Help them get there from position 0.

The bug jumps according to the following rules:

It can jump exactly a positions forward (to the right).
It can jump exactly b positions backward (to the left).
It cannot jump backward twice in a row.
It cannot jump to any forbidden positions.
The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.

 

Example 1:

Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
Output: 3
Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
Example 2:

Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
Output: -1
Example 3:

Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
Output: 2
Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.
 

Constraints:

1 <= forbidden.length <= 1000
1 <= a, b, forbidden[i] <= 2000
0 <= x <= 2000
All the elements in forbidden are distinct.
Position x is not forbidden.

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int res=0, mx=0;
        queue<vector<int>> q;
        q.push({0, 0});
        unordered_set<int> visited={0};
        for (auto& f:forbidden) {
            mx=max(mx, f);
            visited.insert((f<<16) | 1);
            visited.insert((f<<16) | 2);
        }
        mx=max(mx, x)+a+b;
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                if (f[0]==x) return res;
                
                int np=f[0]+a;
                if (np<=mx && visited.find(((np<<16) | 1))==visited.end()) {
                    q.push({np, 1});
                    visited.insert((np<<16) | 1);
                }
                if (f[1]!=2) {
                    np=f[0]-b;
                    if (np>0 && visited.find(((np<<16) | 2))==visited.end()) {
                        q.push({np, 2});
                        visited.insert((np<<16) | 2);
                    }
                }
            }
            res++;
            
        }
        
        return -1;
    }
};

