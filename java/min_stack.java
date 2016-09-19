public class MinStack {

    ArrayDeque<Integer> stack;
    ArrayDeque<Integer> min;
    /** initialize your data structure here. */
    public MinStack() {
        stack=new ArrayDeque<>();
        min=new ArrayDeque<>();
    }
    
    public void push(int x) {
        stack.add(x);
        if (min.isEmpty()||x<=min.peekLast()) min.add(x);
    }
    
    public void pop() {
        if (!stack.isEmpty()) {
            if (min.peekLast().equals(stack.peekLast())) min.pollLast();
            stack.pollLast();
        }
    }
    
    public int top() {
        if (!stack.isEmpty()) {
            return stack.peekLast();
        } else {
            return -1;
        }
    }
    
    public int getMin() {
        if (!min.isEmpty()) {
            return min.peekLast();
        } else {
            return -1;
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
