225. Implement Stack using Queues 
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.

Hide Company Tags Bloomberg
Hide Tags Stack Design
Hide Similar Problems (E) Implement Queue using Stacks

two queues:

  class Stack {
  public:
	  queue<int> q1;
	  queue<int> q2;

      // Push element x onto stack.
      void push(int x) {
    	  if(q1.empty()) q2.push(x);
    	  else if(q2.empty()) q1.push(x);
      }

      // Removes the element on top of the stack.
      void pop() {
    	  if (q1.empty() && q2.empty()) {
    		  return;
    	  } else if (q1.empty()) {
    		  while(q2.size()>1) {
    			  q1.push(q2.front());
    			  q2.pop();
    		  }
    		  q2.pop();
    	  } else if (q2.empty()) {
    		  while (q1.size()>1) {
    			  q2.push(q1.front());
    			  q1.pop();
    		  }
    		  q1.pop();
    	  }
      }

      // Get the top element.
      int top() {
    	  if (q1.empty() && q2.empty()) {
    		  return 0;
    	  } else if (q1.empty()) {
    		  while (q2.size()>1) {
    			  q1.push(q2.front());
    			  q2.pop();
    		  }
    		  int res=q2.front();
    		  q1.push(res);
    		  q2.pop();
    		  return res;
    	  } else if (q2.empty()) {
    		  while (q1.size()>1) {
    			  q2.push(q1.front());
    			  q1.pop();
    		  }
    		  int res=q1.front();
    		  q2.push(res);
    		  q1.pop();
    		  return res;
    	  }
      }

      // Return whether the stack is empty.
      bool empty() {
    	  return (q1.empty() && q2.empty());
      }
  };


one queue:

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int i=q.size()-1;
        while (i>0) {
            q.push(q.front());
            q.pop();
            i--;
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
     }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

