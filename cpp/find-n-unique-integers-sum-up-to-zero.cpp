5295. Find N Unique Integers Sum up to Zero
Easy

9

1

Add to List

Share
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000

Microsoft
|
LeetCode

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int l=0, r=n-1, num=1;
        while (l<r) {
            res[l++]=num;
            res[r--]=-num;
            num++;
        }
        
        return res;
    }
};

