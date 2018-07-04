864. Random Pick with Blacklist
DescriptionHintsSubmissionsDiscussSolution
Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.

Optimize it such that it minimizes the call to system’s Math.random().

Note:

1 <= N <= 1000000000
0 <= B.length < min(100000, N)
[0, N) does NOT include N. See interval notation.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
Output: [null,0,0,0]
Example 2:

Input: 
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
Output: [null,1,1,1]
Example 3:

Input: 
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
Output: [null,0,0,2]
Example 4:

Input: 
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
Output: [null,1,3,1]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

ass Solution {
public:
    Solution(int N, vector<int> blacklist) {
        size=N-blacklist.size();
        for (auto b:blacklist) mp[b];
        for (auto b:blacklist) {
            if (b<size) {
                while (mp.find(--N)!=mp.end());
                mp[b]=N;
            }
        }
    }
    
    int pick() {
        int v=rand()%size;
        if (mp.find(v)!=mp.end()) v=mp[v];
        return v;
    }
private:
    int size;
    unordered_map<int,int> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
