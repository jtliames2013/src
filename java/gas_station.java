public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n=gas.length;
        if (n==0) return -1;
        int[] left=new int[n];
        for (int i=0; i<n; i++) {
            left[i]=gas[i]-cost[i];
        }
        
        int sum=0;
        int total=0;
        int start=0;
        for (int i=0; i<n; i++) {
            sum+=left[i];
            total+=left[i];
            if (sum<0) {
                sum=0;
                start=i+1;
            }
        }
        
        if (total>=0) return start;
        else return -1;
    }
}
