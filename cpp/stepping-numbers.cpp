1215. Stepping Numbers
Medium

65

4

Add to List

Share
A Stepping Number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the Stepping Numbers in the range [low, high] inclusive.

 

Example 1:

Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
 

Constraints:

0 <= low <= high <= 2 * 10^9

Epic Systems
|
LeetCode

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if (low>high) return res;
        if (low==0) res.push_back(0);
        queue<long> q;
        for (int i=1; i<=9; ++i) q.push(i);
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            if (f>=low && f<=high) res.push_back(f);
            
            int digit=f%10;
            if (digit>0) {
                long num=f*10+digit-1;
                if (num<=high) q.push(num);
            }
            if (digit<9) {
                long num=f*10+digit+1;
                if (num<=high) q.push(num);
            }
        }
        return res;
    }
};

