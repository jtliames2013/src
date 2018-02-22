786. K-th Smallest Prime Fraction
DescriptionHintsSubmissionsDiscussSolution
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length + 1) / 2.

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> res={0,0};
        int n=A.size();
        if (n==0) return res;
        // { numerator, denominator }
        auto comp=[&A](pair<int,int>& a, pair<int,int>& b){ return A[a.first]*A[b.second]>A[a.second]*A[b.first]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({0, n-1});
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            K--;
            if (K==0) {
                res[0]=A[t.first];
                res[1]=A[t.second];
                return res;
            }
            
            if (t.first==0 && t.second>0) pq.push({t.first,t.second-1});
            if (t.first<n-1) pq.push({t.first+1,t.second});
        }
        return res;
    }
};
