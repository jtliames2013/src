public class Solution {
    boolean isPalin(String s, int i) {
        int l=0, r=i;
        while (l<r) {
            if (s.charAt(l)!=s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
    
    public String shortestPalindrome(String s) {
        StringBuilder sb=new StringBuilder();
        
        for (int i=s.length()-1; i>=0; i--) {
            if (isPalin(s, i)) {
                sb.append(s.substring(i+1));
                break;
            }
        }
        sb.reverse();
        sb.append(s);
        return sb.toString();
    }
}
