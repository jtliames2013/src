1643. Kth Smallest Instructions
Hard

155

3

Add to List

Share
Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.

The instructions are represented as a string, where each character is either:

'H', meaning move horizontally (go right), or
'V', meaning move vertically (go down).
Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.

However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.

Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.

 

Example 1:



Input: destination = [2,3], k = 1
Output: "HHHVV"
Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
Example 2:



Input: destination = [2,3], k = 2
Output: "HHVHV"
Example 3:



Input: destination = [2,3], k = 3
Output: "HHVVH"
 

Constraints:

destination.length == 2
1 <= row, column <= 15
1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        string res;
        int r=destination[0], c=destination[1], steps=r+c, down=r;
        for (int i=0; i<r+c; ++i) {
            steps--;
            int num=comb(steps, down);
            if (num>=k) {
                res+='H';
            } else {
                k-=num;
                down--;
                res+='V';
            }
        }
        return res;
    }
private:
    long comb(int n, int k) {
        long res=1;
        for (int i=1, j=n-k+1; i<=k; i++, j++) {
            res=res*j/i;
        }
        return res;
    }
};

