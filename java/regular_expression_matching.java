public class Solution {
    boolean isMatch(char[] s, int i, char[] p, int j) {
        if (j==p.length) return i==s.length;
        if (j==p.length-1 || p[j+1]!='*') {
            return (i<s.length && (p[j]=='.' || s[i]==p[j]) && isMatch(s, i+1, p, j+1));
        } else {
            while (i<s.length && (p[j]=='.' || s[i]==p[j])) {
                if (isMatch(s, i, p, j+2)==true) return true;
                i++;
            }
            return isMatch(s, i, p, j+2);
        }
    }
    
    public boolean isMatch(String s, String p) {
        return isMatch(s.toCharArray(), 0, p.toCharArray(), 0);
    }
}
