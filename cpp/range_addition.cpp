70. Range Addition 
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]

Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Hint:

Thinking of using advanced data structures? You are thinking it too complicated.
For each update operation, do you really need to update all elements between i and j?
Update only the first and end element is sufficient.
The optimal time complexity is O(k + n) and uses O(1) extra space.
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Array

这道题的提示说了我们肯定不能把范围内的所有数字都更新，而是只更新开头结尾两个数字就行了，那么我们的做法就是在开头坐标startIndex位置加上inc，而在结束位置加1的地方加上-inc，那么根据题目中的例子，我们可以得到一个数组，nums = {-2, 2, 3, 2, -2, -3}，然后我们发现对其做累加和就是我们要求的结果result = {-2, 0, 3, 5, 3}

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        if (length==0) return vector<int>();
        vector<int> res(length+1);
        
        for (auto u:updates) {
            res[u[0]]+=u[2];
            res[u[1]+1]-=u[2];
        }
        
        for (int i=1; i<length; i++) res[i]+=res[i-1];
        
        res.pop_back();
        return res;
    }
};
