128. Longest Consecutive Sequence 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.


既然要O(n)算法，排序显然不行，所以自然想到用hash table。将序列中的所有数存到一个unordered_set中。对于序列里任意一个数A[i]，我们可以通过set马上能知道A[i]+1和A[i]-1是否也在序列中。如果在，继续找A[i]+2和A[i]-2，以此类推，直到将整个连续序列找到。为了避免在扫描到A[i]-1时再次重复搜索该序列，在从每次搜索的同时将搜索到的数从set中删除。直到set中为空时，所有连续序列搜索结束。

复杂度：由于每个数字只被插入set一次，并删除一次，所以算法是O(n)的。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> st;
        for (int i:nums) st.insert(i);
        
        while (!st.empty()) {
            int num=*st.begin();
            st.erase(num);
            int l=num-1, r=num+1;
            
            while (1) {
                if (st.find(l)==st.end()) break;
                st.erase(l);
                l--;
            }
            while (1) {
                if (st.find(r)==st.end()) break;
                st.erase(r);
                r++;
            }
            longest=max(longest, r-l-1);
        }
        
        return longest;
    }
};

2.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> st;
        for (auto n:nums) st.insert(n);
       
        for (auto n:nums) {
            if (st.find(n)!=st.end()) {
                int left=n, right=n;
                while (1) {
                    right++;
                    if (st.find(right)==st.end()) break;
                    st.erase(right);
                }                

                while (1) {
                    left--;
                    if (st.find(left)==st.end()) break;
                    st.erase(left);
                }                

                longest=max(longest, right-left-1);                
                st.erase(n);
            }    
        }
       
        return longest;
    }
};

int main()
{
	return 0;
}

