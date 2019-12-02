952. Largest Component Size by Common Factor
Hard

141

34

Favorite

Share
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n=A.size(), res=0;
        vector<int> root(n), size(n);
        for (int i=0; i<n; ++i) {
            root[i]=i;
            size[i]=1;
        }
        
        unordered_map<int, int> mp;        
        for (int i=0; i<n; ++i) {
            for (int j=2; j*j<=A[i]; ++j) {
                if (A[i]%j==0) {
                    int k=A[i]/j;
                    if (mp.find(j)==mp.end()) mp[j]=i;
                    else uni(root, size, i, mp[j]);
                    if (mp.find(k)==mp.end()) mp[k]=i;
                    else uni(root, size, i, mp[k]);
                }
            }
            
            if (mp.find(A[i])==mp.end()) mp[A[i]]=i;
            else uni(root, size, i, mp[A[i]]);
        }
        
        for (auto& i:size) res=max(res, i);
        return res;
    }
private:
    void uni(vector<int>& root, vector<int>& size, int i, int j) {
        int r1=find(root, i), r2=find(root, j);
        if (r1!=r2) {
            root[r1]=r2;
            size[r2]+=size[r1];
        }
    }
    
    int find(vector<int>& root, int i) {
        while (i!=root[i]) i=root[i];
        return i;
    }
};

