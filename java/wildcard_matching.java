public class Solution {
    public boolean isMatch(String s, String p) {
        int i=0, j=0;
        int sIndex=0, pIndex=0;
        boolean star=false;
        while (i<s.length()) {
            if (j==p.length() || (p.charAt(j)!='?' && p.charAt(j)!='*')) {
                if (j==p.length() || s.charAt(i)!=p.charAt(j)) {
                    if (star==false) return false;
                    else {
                        j=pIndex;
                        i=++sIndex;
                    }
                } else {
                    i++;
                    j++;
                }
            } else if (p.charAt(j)=='?') {
                i++;
                j++;
            } else {
                while (j<p.length()&&p.charAt(j)=='*') j++;
                if (j==p.length()) return true;
                star=true;
                sIndex=i;
                pIndex=j;
            }
        }
        
        while (j<p.length()&&p.charAt(j)=='*') j++;
        if (j==p.length()) return true;
        else return false;
    }
}
