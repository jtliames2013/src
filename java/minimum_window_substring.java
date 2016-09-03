import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;

public class HelloWorld {
    public String minWindow(String s, String t) {
        Map<Character, Integer> count=new HashMap<Character, Integer>();
        for (char c:t.toCharArray()) {
            Integer cnt=count.get(c);
            if (cnt==null) {
                count.put(c, 1);
            } else {
                count.put(c, cnt+1);
            }
        }
        
        int total=0;        
        int start=0, end=0, minlen=Integer.MAX_VALUE;
        for (int l=0, r=0; r<s.length(); r++) {
            if (count.containsKey(s.charAt(r))) {
                count.put(s.charAt(r), count.get(s.charAt(r))-1);
                if (count.get(s.charAt(r))>=0) total++;
            }
            
            while (total==t.length()) {
                if (minlen>r-l+1) {
                    minlen=r-l+1;
                    start=l;
                    end=r;
                }
                
                if (count.containsKey(s.charAt(l))) {
                    count.put(s.charAt(l), count.get(s.charAt(l))+1);
                    if (count.get(s.charAt(l))>0) total--;
                }
                
                l++;
            }
        }
        
        if (minlen==Integer.MAX_VALUE) return "";
        else return s.substring(start, end+1);
    }
    
    public static void main(String[] args) {
        HelloWorld h=new HelloWorld();
        String res=h.minWindow("a", "a");
    }
}

