public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb=new StringBuilder();
        int i=a.length()-1, j=b.length()-1;
        boolean carry=false;
        int num=0;
        while (i>=0 || j>=0) {
            if (i>=0&&j>=0) {
                num=a.charAt(i)-'0'+b.charAt(j)-'0';
                i--;
                j--;
            } else if (i>=0) {
                num=a.charAt(i)-'0';
                i--;
            } else if (j>=0) {
                num=b.charAt(j)-'0';
                j--;
            }
            if (carry) {
                num++;
                carry=false;
            }
            if (num>1) {
                num%=2;
                carry=true;
            }
            sb.append((char)(num+'0'));
        }
        
        if (carry==true) {
            sb.append('1');
        }
        sb.reverse();
        return sb.toString();
    }
}
