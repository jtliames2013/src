528. Random Pick with Weight
Medium

365

677

Favorite

Share
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

class Solution {
public:
    Solution(vector<int>& w) {
        int n=w.size();
        if (n==0) return;
        sums=w;
        for (int i=1; i<n; ++i) sums[i]+=sums[i-1];
    }
    
    int pickIndex() {
        int index=rand()%sums.back()+1, l=0, r=sums.size()-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (sums[mid]==index) return mid;
            else if (sums[mid]<index) l=mid+1;
            else r=mid;
        }
        return r;
        
    }
private:
    vector<int> sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
