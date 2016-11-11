public class Solution {
    public int longestValidParentheses(String s) {
        int longest=0;
        int left=-1;
        Stack<Integer> stack=new Stack<>();
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i)=='(') stack.push(i);
            else {
                if (stack.isEmpty()) left=i;
                else {
                    stack.pop();
                    if (stack.isEmpty()) longest=Math.max(longest, i-left);
                    else longest=Math.max(longest, i-stack.peek());
                }
            }
        }
        return longest;
    }
}
