public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> pos=new HashMap<>();
        int res=0;
        int start=0;
        for (int i=0; i<s.length(); i++) {
            if (pos.containsKey(s.charAt(i))) {
                int j=pos.get(s.charAt(i));
                res=Math.max(res, i-start);
                for (int k=start; k<=j; k++) {
                    pos.remove(s.charAt(k));
                }
                start=j+1;
            }
            
            pos.put(s.charAt(i), i);
        }
        res=Math.max(res, s.length()-start);
        
        return res;
    }
}
