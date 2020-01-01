1183. Maximum Number of Ones
Hard

43

6

Add to List

Share
Consider a matrix M with dimensions width * height, such that every cell has value 0 or 1, and any square sub-matrix of M of size sideLength * sideLength has at most maxOnes ones.

Return the maximum possible number of ones that the matrix M can have.

 

Example 1:

Input: width = 3, height = 3, sideLength = 2, maxOnes = 1
Output: 4
Explanation:
In a 3*3 matrix, no 2*2 sub-matrix can have more than 1 one.
The best solution that has 4 ones is:
[1,0,1]
[0,0,0]
[1,0,1]
Example 2:

Input: width = 3, height = 3, sideLength = 2, maxOnes = 2
Output: 6
Explanation:
[1,0,1]
[1,0,1]
[1,0,1]
 

Constraints:

1 <= width, height <= 100
1 <= sideLength <= width, height
0 <= maxOnes <= sideLength * sideLength

Qualcomm
|
LeetCode

Consider a position 0<i<sideLength and 0<j<sideLength set to 1, any position x%sideLength==i and y%sideLength==j
can be set to 1 without violating the condition. Therefore we only consider position inside sideLength.

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int res=0;
        vector<int> count;
        for (int i=0; i<sideLength; ++i) {
            for (int j=0; j<sideLength; ++j) {
                count.push_back((width/sideLength+(i<width%sideLength?1:0))*(height/sideLength+(j<height%sideLength?1:0)));
            }
        }

        sort(count.begin(), count.end(), greater<int>());
        for (int i=0; i<maxOnes; ++i) res+=count[i];
        return res;
    }
};

