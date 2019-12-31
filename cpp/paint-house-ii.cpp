265. Paint House II  QuestionEditorial Solution  My Submissions
Total Accepted: 8966 Total Submissions: 24967 Difficulty: Hard
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

LinkedIn
|
2

Google
|
3

Uber
|
2

Facebook
|
LeetCode

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if (n==0) return 0;
        int k=costs[0].size();
        int minidx1=-1, minidx2=-1, previdx1, previdx2;
        
        for (int i=0; i<n; i++) {
            previdx1=minidx1;
            previdx2=minidx2;
            minidx1=minidx2=-1;
            
            for (int j=0; j<k; j++) {
                if (j!=previdx1) costs[i][j]+=i==0?0:costs[i-1][previdx1];
                else costs[i][j]+=i==0?0:costs[i-1][previdx2];
                
                if (minidx1==-1 || costs[i][j]<costs[i][minidx1]) {
                    minidx2=minidx1;
                    minidx1=j;
                } else if (minidx2==-1 || costs[i][j]<costs[i][minidx2]) {
                    minidx2=j;
                }
            }
        }
        
        return costs[n-1][minidx1];
    }
};

