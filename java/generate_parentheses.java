public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        StringBuilder sb=new StringBuilder();
        genParen(res, sb, n, n);
        return res;
    }
    private void genParen(List<String> res, StringBuilder sb, int l, int r) {
        if (l==0&&r==0) {
            res.add(sb.toString());
            return;
        }
        
        if (l>0) {
            sb.append('(');
            genParen(res, sb, l-1, r);
            sb.deleteCharAt(sb.length()-1);
        }
        if (r>0 && r>l) {
            sb.append(')');
            genParen(res, sb, l, r-1);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}
