public class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb=new StringBuilder();
        while (n>0) {
            int num=n%26;
            if (num==0) {
                n-=26;
                num=26;
            }
            sb.append((char)(num+'A'-1));
            n/=26;
        }
        sb.reverse();
        return sb.toString();
    }
}
