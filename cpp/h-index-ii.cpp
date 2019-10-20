275. H-Index II 
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
Subscribe to see which companies asked this question

1.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if (n==0) return 0;
        int l=0, r=n-1, mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (citations[mid]>=n-mid) r=mid-1;
            else l=mid+1;
        }
        return n-l;
    }
};

2.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if (n==0) return 0;
        int l=0, r=n, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (citations[mid]<n-mid) l=mid+1;
            else r=mid;
        }
        return n-r;
    }
};
