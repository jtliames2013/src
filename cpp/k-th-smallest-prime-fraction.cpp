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

1. TLE
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> res(2);
        int n=A.size();
        // { numerator, denominator }
        auto comp=[&](pair<int,int>& a, pair<int,int>& b){ return A[a.first]*A[b.second]>A[a.second]*A[b.first]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({0, n-1});
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            K--;
            if (K==0) {
                res[0]=A[t.first];
                res[1]=A[t.second];
                break;
            }
            
            if (t.first==0 && t.second>1) pq.push({t.first,t.second-1});
            if (t.first<n-1) pq.push({t.first+1,t.second});
        }
        return res;
    }
};

2.
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> res;
        int n=A.size();
        double l=0, r=1, mid;
        while (1) {
            mid=(l+r)/2;
            int count=0, p=0, q=1; // p/q start from 0
            for (int i=0, j=0; i<n && j<n; ++i) {
                while (j<n && A[j]*mid<A[i]) j++;
                count+=(n-j);
                if (j<n && p*A[j]<A[i]*q) {
                    // p/q = max(p/q, A[i]/A[j])
                    p=A[i];
                    q=A[j];
                }
            }
            if (count<K) l=mid;
            else if (count>K) r=mid;
            else {
                res={p, q};
                break;
            }
        }
        return res;
    }
};

