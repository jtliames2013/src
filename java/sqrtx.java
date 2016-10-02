public class Solution {
    public int mySqrt(int x) {
        if (x<0) return -1;
        if (x==0) return 0;
        if (x==1) return 1;
        int l=0, r=x;
        
        while (l<=r) {
            int mid=l+(r-l)/2;
            if (x/mid==mid) return mid;
            else if (x/mid>mid) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
}
