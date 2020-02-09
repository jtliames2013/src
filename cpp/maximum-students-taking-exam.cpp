1349. Maximum Students Taking Exam
Hard

31

0

Add to List

Share
Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.

 

Example 1:


Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 
Example 2:

Input: seats = [[".","#"],
                ["#","#"],
                ["#","."],
                ["#","#"],
                [".","#"]]
Output: 3
Explanation: Place all students in available seats. 

Example 3:

Input: seats = [["#",".",".",".","#"],
                [".","#",".","#","."],
                [".",".","#",".","."],
                [".","#",".","#","."],
                ["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.
 

Constraints:

seats contains only characters '.' and'#'.
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(), n=seats[0].size();
        vector<vector<int>> dp(m+1, vector<int>(1<<n));

        for (int i=1; i<=m; ++i) {
            int mask=0;
            for (int j=0; j<n; ++j) {
                mask<<=1;
                if (seats[i-1][j]=='#') mask|=1;
            }
            for (int j=0; j<(1<<n); ++j) {
                if ((j & mask)!=0) continue; // no sit on broken seat
                if (j & (j>>1)) continue; // no adjacent 1 bit
                int count=__builtin_popcount(j);
                for (int k=0; k<(1<<n); ++k) {
                    if ((j & (k>>1)) || (j & (k<<1))) continue;
                    dp[i][j]=max(dp[i][j], dp[i-1][k]+count);
                }
            }
        }

        return *max_element(dp[m].begin(), dp[m].end());
    }
};

