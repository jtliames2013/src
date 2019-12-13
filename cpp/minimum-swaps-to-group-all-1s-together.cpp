1151. Minimum Swaps to Group All 1's Together
Medium

86

0

Favorite

Share
Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

 

Example 1:

Input: [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
Example 2:

Input: [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.
Example 3:

Input: [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
 

Note:

1 <= data.length <= 10^5
0 <= data[i] <= 1

Expedia
|
LeetCode


find the minimum number of 0s in sliding window of size of number of 1s

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size(), ones=0, zeros=0, res=n;
        for (auto& d:data) {
            if (d==1) ones++;
        }
        for (int i=0; i<n; ++i) {
            if (data[i]==0) zeros++;
            if (i>=ones) zeros-=data[i-ones]==0?1:0;
            if (i>=ones-1) res=min(res, zeros);            
        }
        return res;
    }
};

