public class Solution {
    public String multiply(String num1, String num2) {
        int m=num1.length();
        int n=num2.length();
        if (m==0||n==0) return "";
        StringBuilder sb=new StringBuilder();
        int carry=0, num;
        
        for (int j=n-1; j>=0; j--) {
            for (int i=m-1; i>=0; i--) {
                num=(num1.charAt(i)-'0')*(num2.charAt(j)-'0')+carry;
                carry=num/10;
                num%=10;
                int index=(n-1-j)+(m-1-i);
                if (index<sb.length()) {
                    int sum=num+sb.charAt(index)-'0';
                    if (sum>9) {
                        carry++;
                        sum%=10;
                    }
                    sb.setCharAt(index, (char)(sum+'0'));
                } else {
                    sb.append((char)(num+'0'));
                }
            }
            if (carry>0) sb.append((char)(carry+'0'));
            carry=0;
        }

        int k;
        for (k=sb.length()-1; k>0; k--) {
            if (sb.charAt(k)!='0') break;
        }   
        sb.delete(k+1, sb.length());
        
        sb.reverse();
        return sb.toString();
    }
}
