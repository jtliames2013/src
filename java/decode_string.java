public class Solution {
    int dfs(char[] s, StringBuilder sb, int start) {
        for (int i=start; i<s.length;) {
            if (Character.isLetter(s[i])) {
                sb.append(s[i]);
                i++;
            } else if (Character.isDigit(s[i])) {
                int num=0;
                while (i<s.length && Character.isDigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                StringBuilder curr=new StringBuilder();
                int last=dfs(s, curr, i);
                for (int j=0; j<num; j++) {
                    sb.append(curr.toString());
                }
                i=last+1;
            } else if (s[i]==']') {
                return i;
            } else {
                i++;
            }
        }
        return 0;
    }
    
    public String decodeString(String s) {
        char[] encoded=s.toCharArray();
        StringBuilder sb=new StringBuilder();
        dfs(encoded, sb, 0);
        return sb.toString();
    }
}
