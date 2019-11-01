996. Number of Squareful Arrays
Hard

190

15

Favorite

Share
Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

 

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
 

Note:

1 <= A.length <= 12
0 <= A[i] <= 1e9

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int res=0;
        unordered_map<int, int> count;
        unordered_map<int, unordered_set<int>> pair;
        for (auto a:A) count[a]++;
        for (auto itera:count) {
            for (auto iterb:count) {
                int x=itera.first, y=iterb.first, s=sqrt(x+y);
                if (s*s==x+y) pair[x].insert(y);
            }
        }
        
        for (auto iter:count) dfs(res, count, pair, iter.first, A.size()-1);
        return res;
    }
private:
    void dfs(int& res, unordered_map<int, int>& count, unordered_map<int, unordered_set<int>>& pair, int start, int left) {        
        if (left==0) {
            res++;
            return;
        }
        count[start]--;
        for (auto neighbor:pair[start]) {
            if (count[neighbor]>0) dfs(res, count, pair, neighbor, left-1);
        }
        count[start]++;
    }
};
