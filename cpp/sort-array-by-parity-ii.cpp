922. Sort Array By Parity II
Easy

173

16

Favorite

Share
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int even=0, odd=1; even<A.size() && odd<A.size(); ) {
            if (A[even]%2==0) {
                even+=2;
            } else if (A[odd]%2!=0) {
                odd+=2;
            } else {
                swap(A[even], A[odd]);
                even+=2;
                odd+=2;
            }
        }
        
        return A;
    }
};

