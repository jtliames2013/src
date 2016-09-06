public class Solution {
    public int numTrees(int n) {
        if (n<0) return 0;
        int[] count=new int[n+1];
        count[0]=1;
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                count[i]+=count[j-1]*count[i-j];
            }
        }
        
        return count[n];
    }
}
