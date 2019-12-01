927. Three Equal Parts
Hard

126

42

Favorite

Share
Given an array A of 0s and 1s, divide the array into 3 non-empty parts such that all of these parts represent the same binary value.

If it is possible, return any [i, j] with i+1 < j, such that:

A[0], A[1], ..., A[i] is the first part;
A[i+1], A[i+2], ..., A[j-1] is the second part, and
A[j], A[j+1], ..., A[A.length - 1] is the third part.
All three parts have equal binary value.
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

 

Example 1:

Input: [1,0,1,0,1]
Output: [0,3]
Example 2:

Input: [1,1,0,1,1]
Output: [-1,-1]
 

Note:

3 <= A.length <= 30000
A[i] == 0 or A[i] == 1

Intuition

Each part has to have the same number of ones in their representation. The algorithm given below is the natural 
continuation of this idea.

Algorithm

Say S is the number of ones in A. Since every part has the same number of ones, they all should have T = S / 3 ones.

If S isn't divisible by 3, the task is impossible.

We can find the position of the 1st, T-th, T+1-th, 2T-th, 2T+1-th, and 3T-th one. The positions of these ones form 3 intervals: 
[i1, j1], [i2, j2], [i3, j3]. (If there are only 3 ones, then the intervals are each length 1.)

Between them, there may be some number of zeros. The zeros after j3 must be included in each part: say there are z of 
them (z = S.length - j3).

So the first part, [i1, j1], is now [i1, j1+z]. Similarly, the second part, [i2, j2], is now [i2, j2+z].

If all this is actually possible, then the final answer is [j1+z, j2+z+1].


ass Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n=A.size(), ones=0;
        for (auto a:A) {
            if (a==1) ones++;
        }
        
        if (ones==0) return {0, n-1};
        else if (ones%3!=0) return {-1, -1};
        ones/=3;
        
        int i=0, first=-1, second=-1, third, cnt=0;
        for (; i<n; ++i) {
            if (A[i]==1) {
                cnt++;
                if (first==-1) first=i;                
            }                     
            if (cnt==ones+1) {
                if (second==-1) second=i;
            } else if (cnt==2*ones+1) {
                third=i;
                break;
            }
        }

        while (third<n && A[first]==A[second] && A[second]==A[third]) {
            first++;
            second++;
            third++;
        }
        if (third==n) return {first-1, second};
        else return {-1, -1};
    }
};

