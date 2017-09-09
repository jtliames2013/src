Min Queue, 跟Min Stack类似， 实现一个Queue， 然后O（1）复杂度获得这个Queue里最小的元素。

class MinQueue {
public:
    /** initialize your data structure here. */
    MinQueue() {

    }

    void push(int x) {
    	data.push_back(x);
    	if (min.empty() || x<=min.back()) min.push_back(x);
    }

    void pop() {
    	if (!data.empty()) {
    		if (data.front()==min.back()) min.pop_back();
    		data.pop_front();
    	}
    }

    int top() {
    	if (data.empty()) return 0;
    	return data.front();
    }

    int getMin() {
    	if (min.empty()) return 0;
    	return min.back();
    }
private:
    list<int> data;
    vector<int> min;
};

