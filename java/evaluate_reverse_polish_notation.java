public class Solution {
    boolean isOp(String s) {
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
    }
    
    int calc(int a, int b, String op) {
        if (op.equals("+")) return a+b;
        else if (op.equals("-")) return a-b;
        else if (op.equals("*")) return a*b;
        else if (op.equals("/")) return a/b;
        else return -1;
    }
    
    public int evalRPN(String[] tokens) {
        List<Integer> nums=new ArrayList<>();
        for (int i=0; i<tokens.length; i++) {
            if (isOp(tokens[i])) {
                if (nums.size()<2) return -1;
                int b=nums.get(nums.size()-1);
                nums.remove(nums.size()-1);
                int a=nums.get(nums.size()-1);
                nums.remove(nums.size()-1);
                nums.add(calc(a, b, tokens[i]));
            } else {
                nums.add(Integer.parseInt(tokens[i]));
            }
        }    
        return nums.get(nums.size()-1);
    }
}
