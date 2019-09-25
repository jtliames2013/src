1004. Max Consecutive Ones III
Medium

352

7

Favorite

Share
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 

Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 

Find the longest subarray with at most K zeros.

1.
Sliding window size does not decrease and increases when zeros contained is at most K.
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0, r=0;
        for (; r<A.size(); ++r) {
            if (A[r]==0) K--;
            if (K<0) {
                if (A[l++]==0) K++;
            }
        }

        return r-l;
    }
};


2.
sliding window is the current longest subarray
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0, r=0, len=0;
        for (; r<A.size(); ++r) {
            if (A[r]==0) K--;
            if (K<0) {
                len=max(len, r-l);                
                while (K<0) {
                    if (A[l++]==0) K++;                    
                }                
            }            
        }

        len=max(len, r-l);
        return len;
    }
};

