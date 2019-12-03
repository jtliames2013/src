805. Split Array With Same Average
DescriptionHintsSubmissionsDiscussSolution
In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].


If the array of size n can be splitted into group A and B with same mean, assuming A is the smaller group, then

  totalSum/n = Asum/k = Bsum/(n-k), where k = A.size() and 1 <= k <= n/2;
  Asum = totalSum*k/n, which is an integer. So we have totalSum*k%n == 0;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n=A.size(), m=n/2, total=accumulate(A.begin(), A.end(), 0);
        bool possible=false;
        for (int i=1; i<=m; ++i) {
            if (total*i%n==0) {
                possible=true;
                break;
            }
        }
        if (!possible) return false;
        
        vector<unordered_set<int>> sums(m+1);
        // get all combination sum
        sums[0].insert(0);
        for (auto& a:A) {
            for (int i=m; i>=1; --i) {
                for (auto& s:sums[i-1]) sums[i].insert(s+a);
            }
        }
        
        for (int i=1; i<=m; ++i) {
            if (total*i%n==0 && sums[i].find(total*i/n)!=sums[i].end()) return true;
        }
        return false;
    }
};

