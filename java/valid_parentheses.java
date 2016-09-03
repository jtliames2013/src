import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class HelloWorld {
    public boolean isValid(String s) {
        Stack<Character> stk=new Stack<Character>();
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i)=='(' || s.charAt(i)=='[' || s.charAt(i)=='{') {
                stk.push(s.charAt(i));
            } else if (s.charAt(i)==')') {
                if (stk.empty() || stk.peek()!='(') return false;
                stk.pop();
            } else if (s.charAt(i)==']') {
                if (stk.empty() || stk.peek()!='[') return false;
                stk.pop();
            } else if (s.charAt(i)=='}') {
                if (stk.empty() || stk.peek()!='{') return false;
                stk.pop();
            }
        }
        
        if (stk.empty()) return true;
        else return false;
    }
    
    public static void main(String[] args) {
    }
}

