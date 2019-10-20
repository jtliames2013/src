60. Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Hide Company Tags Twitter
Hide Tags Backtracking Math
Hide Similar Problems (M) Next Permutation (M) Permutations

say n = 4, you have {1, 2, 3, 4}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)

The logic is as follows: for n numbers the permutations can be divided to (n-1)! groups, for n-1 numbers can be divided to (n-2)! groups, and so on. Thus k/(n-1)! indicates the index of current number, and k%(n-1)! denotes remaining index for the remaining n-1 numbers.

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums(n),f(n);
        for (int i=0; i<n; i++) nums[i]=i+1;
        f[0]=1;
        for (int i=1; i<n; i++) f[i]=f[i-1]*i;
        
        k--;
        for (int i=n-1; i>=0; i--) {
            int j=k/f[i];
            res+=nums[j]+'0';
            nums.erase(nums.begin()+j);
            k%=f[i];
        }
        return res;
    }
};

