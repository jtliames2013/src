961. N-Repeated Element in Size 2N Array
Easy

93

73

Favorite

Share
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> st;
        for (int i:A) {
            if (st.find(i)!=st.end()) return i;
            st.insert(i);
        }
        return 0;
    }
};

2.
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i=2; i<A.size(); ++i) {
            if (A[i]==A[i-1] || A[i]==A[i-2]) return A[i];
        }
        
        return A[0];
    }
};

