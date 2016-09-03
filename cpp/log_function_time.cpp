给一串log（function, timestamp，act）, 在single thread的情况下输出各个function执行的时间段
.给一个单核CPU的log，parse log，每一行log三列分别是jobname(String) start/end(boolean) timeStamp(long)

name(String) start/end(boolean) timeStamp(long) . from: 1point3acres.com/bbs
f1 start 0
f2 start 2
f3 start 4
f3 end 5
f2 end 8
f1 end 9

上面log的意思是我们在0开始做f1
在2的时候切换到f2,
4的时候开始做f3，
5的时候f3结束
要返回每个function要用的时间
这个input的返回就是
f1 ： 3
f2 ： 5
f3 ： 1

class Solution {
public:
	void getTime(vector<Entry> log) {
		stack<int> stk;
		int lastTime=0;
		map<int, int> res;

		for (auto l:log) {
			int gap=l.time-lastTime;
			if (!stk.empty()) res[stk.top()]+=gap;
			if (l.start) {
				stk.push(l.id);
			} else {
				stk.pop();
			}
			lastTime=l.time;
		}

		for (auto r:res) cout << r.first << " " << r.second << endl;
	}
};

int main()
{
	vector<Entry> log;
	for (int i=0; i<3; i++) {
		Entry e(i, i*2+1, true);
		log.push_back(e);
	}
	for (int i=2; i>=0; i--) {
		Entry e(i, 20-i, false);
		log.push_back(e);
	}

	Solution s;
	s.getTime(log);
  	return 0;
}

