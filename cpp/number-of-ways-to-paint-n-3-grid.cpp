1411. Number of Ways to Paint N × 3 Grid
Hard

14

1

Add to List

Share
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:

Input: n = 2
Output: 54
Example 3:

Input: n = 3
Output: 246
Example 4:

Input: n = 7
Output: 106494
Example 5:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
grid[i].length == 3
1 <= n <= 5000

class Solution {
public:
    int numOfWays(int n) {
        long a121=6, a123=6, b121, b123;
        // 121: ryr, rgr, yry, ygy, grg, gyg
        // 123: ryg, rgy, yrg, ygr, gry, gyr
        // ryr -> yry, ygy, grg, yrg, gry
        // ryg -> yry, ygy, ygr, gry
        for (int i=1; i<n; ++i) {
            b121=a121*3+a123*2;
            b123=a121*2+a123*2;
            a121=b121%mod;
            a123=b123%mod;
        }
        return (a121+a123)%mod;
    }
private:
    const int mod=1e9+7;
};

