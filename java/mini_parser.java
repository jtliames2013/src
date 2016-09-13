/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {
    public NestedInteger deserialize(String s) {
        int num;
        NestedInteger res=null;
        boolean neg=false;
        Stack<NestedInteger> stack=new Stack<NestedInteger>();
        for (int i=0; i<s.length();) {
            if (Character.isDigit(s.charAt(i))) {
                num=0;
                while (i<s.length() && Character.isDigit(s.charAt(i))) {
                    num=num*10+s.charAt(i)-'0';
                    i++;
                }
                
                if (stack.empty()) {
                    return new NestedInteger(neg?-num:num);
                } else {
                    stack.peek().add(new NestedInteger(neg?-num:num));
                }
                neg=false;
            } else if (s.charAt(i)=='-') {
                neg=true;
                i++;
            } else if (s.charAt(i)=='[') {
                NestedInteger n=new NestedInteger();
                if (!stack.empty()) {
                    stack.peek().add(n);
                }
                stack.push(n);
                i++;
            } else if (s.charAt(i)==']') {
                if (stack.size()==1) res=stack.peek();
                stack.pop();
                i++;
            } else {
                i++;
            }
        }
        
        return res;
    }
}
