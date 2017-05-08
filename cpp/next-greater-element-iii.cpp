556. Next Greater Element III Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 3275
Total Submissions: 11979
Difficulty: Medium
Contributors:
a_silver_g
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (E) Next Greater Element I (M) Next Greater Element II

1.
class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        int size=str.size();
        if (size<=1) return -1;
        
        int i;
        for (i=size-1; i>0; i--) {
            if (str[i-1]<str[i]) break;
        }
        if (i==0) return -1;
        
        int k=i-1, j;
        for (j=size-1; j>=i; j--) {
            if (str[j]>str[k]) break;
        }
        swap(str[k], str[j]);
        reverse(str.begin()+i, str.end());

        long res=stol(str);
        if (res>INT_MAX) return -1;
        return res;
    }
};

2. std next_permutation
class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        next_permutation(str.begin(), str.end());
        long res=stol(str);
        if (res>INT_MAX || res<=n) return -1;
        return res;
    }
};

