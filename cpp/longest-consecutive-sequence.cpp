128. Longest Consecutive Sequence 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto n:nums) st.insert(n);
        int res=0;
        while (!st.empty()) {
            int num=*st.begin();
            st.erase(num);
            int l=num-1, r=num+1;
            while (st.find(l)!=st.end()) {
                st.erase(l);
                l--;
            }
            while (st.find(r)!=st.end()) {
                st.erase(r);
                r++;
            }
            res=max(res, r-l-1);
        }
        
        return res;
    }
};

