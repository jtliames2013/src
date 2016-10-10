public class Solution {
    public int trap(int[] height) {
        int volume=0;
        int n=height.length;
        if (n==0) return 0;
        int[] left=new int[n];
        int[] right=new int[n];
        for (int i=1; i<n; i++) {
            left[i]=Math.max(height[i-1], left[i-1]);
        }

        for (int i=n-2; i>=0; i--) {
            right[i]=Math.max(height[i+1], right[i+1]);
            int h=Math.min(left[i],right[i])-height[i];
            if (h>0) {
                volume+=h;
            }
        }
        
        return volume;
    }
}
