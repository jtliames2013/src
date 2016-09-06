public class Solution {
    void buildIsPalin(String s, boolean[][] isPalin) {
        int n=s.length();
        for (int i=0; i<n; i++) {
            for (int j=i; j>=0; j--) {
                if (i==j) isPalin[i][j]=true;
                else if (j==i-1) isPalin[i][j]=(s.charAt(i)==s.charAt(j));
                else {
                    isPalin[i][j]=(s.charAt(i)==s.charAt(j) && isPalin[i-1][j+1]);
                }
            }
        }
    }
    
    void getPartition(List<List<String>> res, String s, List<String> output, boolean[][] isPalin, int start) {
        if (start==s.length()) {
            res.add(new ArrayList<String>(output));
            return;
        }
        
        for (int i=start; i<s.length(); i++) {
            if (isPalin[i][start]) {
                String str=s.substring(start, i+1);
                output.add(str);
                getPartition(res, s, output, isPalin, i+1);
                output.remove(output.size()-1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        List<List<String>> res=new ArrayList<List<String>>();
        int n=s.length();
        if (n==0) return res;
        boolean[][] isPalin=new boolean[n][n];
        buildIsPalin(s, isPalin);
        List<String> output=new ArrayList<String>();
        getPartition(res, s, output, isPalin, 0);
        
        return res;
    }
}
