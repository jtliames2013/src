public class Solution {
    public boolean isAdditiveNumber(String num) {
        int n=num.length();
        
        for (int i=0; i<n/2; i++) {
            if (num.charAt(0)=='0' && i>0) break;
            for (int j=i+1; j<n && j-i<=n/2; j++) {
                if (num.charAt(i+1)=='0' && j-i>1) break;
                
                long a=Long.parseLong(num.substring(0, i+1));
                long b=Long.parseLong(num.substring(i+1, j+1));
                String remain=num.substring(j+1);
                
                while (true) {
                    long c=a+b;
                    String s=((Long)c).toString();
                    if (!remain.startsWith(s)) break;
                    remain=remain.substring(s.length());
                    if (remain.isEmpty()) return true;
                    a=b;
                    b=c;
                }
            }
        }
        
        return false;
    }
}
