873. Length of Longest Fibonacci Subsequence
Medium

303

11

Favorite

Share
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

 

Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].
 

Note:

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
(The time limit has been reduced by 50% for submissions in Java, C, and C++.)

1.
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n, vector<int>(n));
        int res=0;
        for (int i=0; i<n; ++i) mp[A[i]]=i;
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (A[i]-A[j]>=A[j] || mp.find(A[i]-A[j])==mp.end()) {                    
                    dp[j][i]=2;
                } else {
                    dp[j][i]=dp[mp[A[i]-A[j]]][j]+1;
                }
                res=max(res, dp[j][i]);
            }
        }
        return res>2?res:0;
    }
};

2.
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size(), res=0;
        unordered_set<int> st(A.begin(), A.end());
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int a=A[i], b=A[j], c=a+b, l=2;
                while (st.find(c)!=st.end()) {
                    a=b;
                    b=c;
                    c=a+b;
                    l++;
                }
                res=max(res, l);
            }
        }
        return res>2?res:0;
    }
};
