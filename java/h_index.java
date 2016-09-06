public class Solution {
    public int hIndex(int[] citations) {
        int n=citations.length;
        if (n==0) return 0;
        int[] count=new int[n+1];
        for (int i:citations) {
            if (i>n) count[n]++;
            else count[i]++;
        }
        
        int sum=0;
        int index;
        for (index=n; index>=0; index--) {
            sum+=count[index];
            if (sum>=index) break;
        }
        
        return index;
    }
}
