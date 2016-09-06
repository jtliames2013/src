public class Solution {
    public int hIndex(int[] citations) {
        int n=citations.length;
        if (n==0) return 0;
        int l=0, r=n-1;
        int mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            if (citations[mid]==n-mid) return n-mid;
            else if (citations[mid]>n-mid) r=mid-1;
            else l=mid+1;
        }
        
        return n-1-r;
    }
}
