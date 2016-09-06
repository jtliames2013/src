import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import java.util.PriorityQueue;
import java.lang.Math;

public class HelloWorld {    
    int compute(int a, int b, char op) {
        switch(op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        default: return 0;
        }
    }
    
    List<Integer> diffWaysToCompute(Map<String, List<Integer>> results, String input) {
        List<Integer> res=new ArrayList<Integer>();
        for (int i=0; i<input.length(); i++) {
            if (input.charAt(i)=='+' || input.charAt(i)=='-' || input.charAt(i)=='*') {
                String leftStr=input.substring(0, i);
                String rightStr=input.substring(i+1, input.length());
                
                List<Integer> left;
                List<Integer> right;
                if (results.containsKey(leftStr)) {
                    left=results.get(leftStr);
                } else {
                    left=diffWaysToCompute(results, leftStr);
                }
                
                if (results.containsKey(rightStr)) {
                    right=results.get(rightStr);
                } else {
                    right=diffWaysToCompute(results, rightStr);
                }
                
                for (int j=0; j<left.size(); j++) {
                    for (int k=0; k<right.size(); k++) {
                        res.add(compute(left.get(j), right.get(k), input.charAt(i)));
                    }
                }
            }
        }
        
        if (res.isEmpty()) {
            res.add(Integer.parseInt(input));
        }
        results.put(input, res);
        return res;
    }
    
    public List<Integer> diffWaysToCompute(String input) {        
        Map<String, List<Integer>> results=new HashMap<String, List<Integer>>();
        return diffWaysToCompute(results, input);             
    }
         
    public static void main(String[] args) {
    }
}

