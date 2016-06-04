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
	  queue<int> q;

      // Push element x onto stack.
      void push(int x) {
    	  q.push(x);
      }

      // Removes the element on top of the stack.
      void pop() {
    	  int size=q.size();
    	  if (size==0) return;

    	  while (size>1) {
    		  q.push(q.front());
    		  q.pop();
    		  size--;
    	  }
    	  q.pop();
      }

      // Get the top element.
      int top() {
    	  int size=q.size();
    	  if (size==0) return 0;

    	  while (size>1) {
    		  q.push(q.front());
    		  q.pop();
    		  size--;
    	  }
    	  int res=q.front();
    	  q.push(res);
    	  q.pop();
    	  return res;
      }

      // Return whether the stack is empty.
      bool empty() {
    	  return q.empty();
      }
  };

