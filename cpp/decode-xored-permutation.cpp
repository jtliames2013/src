1734. Decode XORed Permutation
Medium

113

4

Add to List

Share
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

 

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]
 

Constraints:

3 <= n < 105
n is odd.
encoded.length == n - 1

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        // e0=a0^a1, e1=a1^a2, e2=a2^a3, e3=a3^a4
        // a0=1^2^...^n^e1^e3
        int n=encoded.size()+1;
        vector<int> res(n);
        int sum=0;
        for (int i=1; i<=n; ++i) {
            sum^=i;
            if (i<n-1 && i%2==1) sum^=encoded[i];
        }
        res[0]=sum;
        for (int i=1; i<n; ++i) res[i]=res[i-1]^encoded[i-1];
        return res;
    }
};

