public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m=matrix.length;
        if (m==0) return 0;
        int n=matrix[0].length;
        if (n==0) return 0;
        int res=Integer.MIN_VALUE;
        boolean scanrow=true;
        if (m>n) {
            scanrow=false;
            int tmp=m;
            m=n;
            n=tmp;
        }
        
        for (int i=0; i<m; i++) {
            int[] sum=new int[n];
            for (int j=i; j>=0; j--) {
                TreeSet<Integer> set=new TreeSet<>();
                int currSum=0;
                set.add(currSum);
                
                for (int col=0; col<n; col++) {
                    sum[col]+=scanrow?matrix[j][col]:matrix[col][j];
                    currSum+=sum[col];
                    Integer ceil=set.ceiling(currSum-k);
                    if (ceil!=null) res=Math.max(res, currSum-ceil);
                    set.add(currSum);
                }
            }
        }
        
        return res;
    }
}
