import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;

public class HelloWorld {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> table=new HashMap<Character, Character>();
        Set<Character> st=new HashSet<Character>();
        
        for (int i=0; i<s.length(); i++) {
            if (table.containsKey(s.charAt(i))) {
                if (table.get(s.charAt(i))!=t.charAt(i)) return false;
            } else {
                if (st.contains(t.charAt(i))) return false;
                st.add(t.charAt(i));
                table.put(s.charAt(i), t.charAt(i));
            }
        }
        
        return true;
    }
    
    public static void main(String[] args) {

    }
}

