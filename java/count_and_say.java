public class Solution {
    public String countAndSay(int n) {
        StringBuilder sb=new StringBuilder();
        if (n<=0) return sb.toString();
        if (n==1) {
            sb.append('1');
            return sb.toString();
        }
        
        sb.append('1');
        for (int i=1; i<n; i++) {
            StringBuilder newSb=new StringBuilder();
            int count=1;
            char ch=sb.charAt(0);
            for (int j=1; j<sb.length(); j++) {
                if (sb.charAt(j)==ch) count++;
                else {
                    newSb.append(count);
                    newSb.append(ch);
                    ch=sb.charAt(j);
                    count=1;
                }
            }
            newSb.append(count);
            newSb.append(ch);
            
            sb=newSb;
        }
        
        return sb.toString();
    }
}
