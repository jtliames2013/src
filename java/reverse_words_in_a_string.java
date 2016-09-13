public class Solution {
    void reverse(char[] s, int start, int end) {
        while (start<end) {
            char tmp=s[start];
            s[start]=s[end];
            s[end]=tmp;
            start++;
            end--;
        }
    }
    public String reverseWords(String s) {
        char[] str=s.toCharArray();
        reverse(str, 0, str.length-1);
        
        for (int i=0; i<str.length;) {
            if (str[i]!=' ') {
                int start=i;
                while (i<str.length && str[i]!=' ') {
                    i++;
                }
                reverse(str, start, i-1);
            } else {
                i++;
            }
        }
        
        int end=0;
        int i=0;
        while (i<str.length && str[i]==' ') i++;
        for (;i<str.length; i++) {
            if (str[i]!=' ' || (i>0 && str[i-1]!=' ')) {
                if (end!=i) {
                    str[end]=str[i];
                }
                end++;
            }
        }
        
        end--;
        while (end>=0 && str[end]==' ') end--;
        
        return new String(str, 0, end+1);
    }
}
