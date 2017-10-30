第二题是设计一个stack，除了实现普通stack的push和pop之外，还有max，min，most frequent number，average，和medium。average很简单，记录sum就行。min和max就是按照leetcode原题来做。most frenquent number我是按照leetcode上least frequent used cache那道题的方法做的，用一个list来记录所有数，list上的每个节点记录一个frequency和所有这个frequency的数字。再用一个map来快速找到数字在list上的位置。medium我觉得最复杂，因为数字是有可能被pop的。做法有点像leetcode上的sliding window median。除了用两个heap来记录所有数字，还需要记录哪些数字被删除了。每次删除一个数字，不需要立马从heap里去删除，而是记录下来，当这个数字出现在heap顶端的时候，我们再删除。最后因为时间不够了，所以没有具体说删除的做法。

class Stack {
public:
    /** initialize your data structure here. */
    Stack() {
    	sum=0;
    	mid=nullptr;
    }

    void push(int x) {
        data.push_back(x);
        if (min.empty() || x<=min.back()) min.push_back(x);
        if (max.empty() || x>=max.back()) max.push_back(x);
        sum+=x;
        st.insert(x);
        if (data.size()==1) {
        	mid=st.begin();
        } else {
        	if (x<*mid) mid--;
        }
    }

    void pop() {
        if (!data.empty()) {
            int t=data.back();
            data.pop_back();
            if (min.back()==t) min.pop_back();
            if (max.back()==t) max.pop_back();
            sum-=t;
            if (data.size()==0) {
            	mid=nullptr;
            } else {
            	if (t<=*mid) mid++;
            	st.erase(st.lower_bound(t));
            }
        }
    }

    int top() {
        if (data.empty()) return 0;
        return data.back();
    }

    int getMin() {
        if (min.empty()) return 0;
        return min.back();
    }

    int getMax() {
        if (min.empty()) return 0;
        return min.back();
    }

    double getAvg() {
    	if (data.empty()) return 0;
    	return sum/data.size();
    }

    double getMedian() {
    	if (data.size()==0) return 0;
    	double m;
    	if (data.size()%2==0) m=((double)*mid+ *prev(mid,1))/2;
    	else m=*mid;
    	return m;
    }

private:
    vector<int> data;
    vector<int> min;
    vector<int> max;
    int sum;
    multiset<int> st;
    multiset<int>::iterator mid;
};


int main()
{
	return 0;
}

