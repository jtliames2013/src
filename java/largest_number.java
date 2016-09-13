public class Solution {
    public String largestNumber(int[] nums) {
        List<String> numstr=new ArrayList<String>();
        for (int i:nums) {
            numstr.add(Integer.toString(i));
        }
        Collections.sort(numstr, new Comparator<String>(){
            @Override
            public int compare(String a, String b) {
                String s1=a+b;
                String s2=b+a;
                return s2.compareTo(s1);
            }
        });
        StringBuilder sb=new StringBuilder();
        
        for (String s:numstr) {
            sb.append(s);
        }
        
        while (sb.length()>1) {
            if (sb.charAt(0)=='0') {
                sb.deleteCharAt(0);
            } else {
                break;
            }
        }
        
        return sb.toString();
    }
}
