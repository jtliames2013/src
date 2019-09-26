932. Beautiful Array
Medium

214

303

Favorite

Share
For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

 

Example 1:

Input: 4
Output: [2,1,4,3]
Example 2:

Input: 5
Output: [3,1,2,5,4]
 

Note:

1 <= N <= 1000
 
Beautiful Array Properties
Saying that an array is beautiful,
there is no i < k < j,
such that A[k] * 2 = A[i] + A[j]

Apply these 3 following changes a beautiful array,
we can get a new beautiful array


1. Deletion
Easy to prove.

2. Addition
If we have A[k] * 2 != A[i] + A[j],
(A[k] + x) * 2 = A[k] * 2 + 2x != A[i] + A[j] + 2x = (A[i] + x) + (A[j] + x)

E.g: [1,3,2] + 1 = [2,4,3].

3. Multiplication
If we have A[k] * 2 != A[i] + A[j],
for any x != 0,
(A[k] * x) * 2 = A[k] * 2 * x != (A[i] + A[j]) * x = (A[i] * x) + (A[j] * x)

E.g: [1,3,2] * 2 = [2,6,4]

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res={1};
        while (res.size()<N) {
            vector<int> tmp;
            for (auto i:res)  {
                if (i*2-1<=N) tmp.push_back(i*2-1);
            }
            for (auto i:res) {
                if (i*2<=N) tmp.push_back(i*2);
            }
            res=tmp;
        }
        
        return res;
    }
};
