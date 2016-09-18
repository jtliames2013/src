public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) return true;
        if (s1.length()!=s2.length()) return false;
        Map<Character, Integer> map=new HashMap<>();
        for (int i=0; i<s1.length(); i++) {
            map.put(s1.charAt(i), map.getOrDefault(s1.charAt(i),0)+1);
            map.put(s2.charAt(i), map.getOrDefault(s2.charAt(i),0)-1);
        }

        for (Map.Entry<Character,Integer> entry:map.entrySet()) {
            if (entry.getValue()!=0) return false;
        }
        
        for (int i=1; i<s1.length(); i++) {
            if (isScramble(s1.substring(0,i),s2.substring(0,i)) && isScramble(s1.substring(i),s2.substring(i))) return true;
            if (isScramble(s1.substring(0,i), s2.substring(s2.length()-i)) && isScramble(s1.substring(i), s2.substring(0,s2.length()-i))) return true;
        }
        
        return false;
    }
}
