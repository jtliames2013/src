public class Solution {
    public String longestPalindrome(String s) {
        int longest=0, start=0, end=0;
        for (int i=0; i<s.length(); i++) {
            int l=0, r=0;
            for (int j=0; j<2; j++) {
                if (j==0) {
                    l=r=i;
                } else {
                    l=i;
                    r=i+1;
                }
                while (l>=0 && r<s.length()) {
                    if (s.charAt(l)!=s.charAt(r)) break;
                    l--;
                    r++;
                }
                if (longest<r-l-1) {
                    longest=r-l-1;
                    start=l+1;
                    end=r;
                }
            }
        }
        return s.substring(start, end);
    }
}
