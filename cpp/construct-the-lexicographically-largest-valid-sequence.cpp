1718. Construct the Lexicographically Largest Valid Sequence
Medium

137

9

Add to List

Share
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int m=2*n-1;
        vector<int> res(m);
        vector<bool> used(n);
        dfs(res, used, m, n, 0);
        return res;
    }
private:
    bool dfs(vector<int>& res, vector<bool>& used, int m, int n, int start) {
        if (start==m) return true;
        if (res[start]>0) return dfs(res, used, m, n, start+1);
        
        for (int i=n-1; i>=0; --i) {
            if (used[i] || (i>0 && (start+i+1>=m || res[start+i+1]>0))) continue;
            used[i]=true;
            res[start]=i+1;
            if (i>0) res[start+i+1]=i+1;
            if (dfs(res, used, m, n, start+1)) return true;
            res[start]=0;
            if (i>0) res[start+i+1]=0;
            used[i]=false;
        }
        return false;
    }
};

