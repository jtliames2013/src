public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res=new ArrayList<>();
        if (digits.isEmpty()) return res;
        StringBuilder sb=new StringBuilder();
        getComb(res, digits, sb, 0);
        return res;
    }
    private void getComb(List<String> res, String digits, StringBuilder sb, int start) {
        if (start==digits.length()) {
            res.add(sb.toString());
            return;
        }
        char[] letters=getChar(digits.charAt(start));
        if (letters.length==0) {
            getComb(res, digits, sb, start+1);
        } else {
            for (int i=0; i<letters.length; i++) {
                sb.append(letters[i]);
                getComb(res, digits, sb, start+1);
                sb.deleteCharAt(sb.length()-1);
            }
        }
    }
    private char[] getChar(char digit) {
        switch (digit) {
            case '2': return new char[]{'a','b','c'};
            case '3': return new char[]{'d','e','f'};
            case '4': return new char[]{'g','h','i'};
            case '5': return new char[]{'j','k','l'};
            case '6': return new char[]{'m','n','o'};
            case '7': return new char[]{'p','q','r','s'};
            case '8': return new char[]{'t','u','v'};
            case '9': return new char[]{'w','x','y','z'};
            default: return new char[]{};
        }
    }
}
