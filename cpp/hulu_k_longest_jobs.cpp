log是指进程运行的记录。一个进程有一个jobname。由于可以并行多次执行，一个jobname下可以有多个jobid。每个jobid会有一个endtime。
要你写一个函数，print out 前k个运行时间最长的进程的jobname和对应的最长endtime。
如果还是不懂的话请私信楼主。有跪掉的代码以及题目详述。
这道题考察的一个是熟练运用语言对字符串进行处理，还有就是两个hashmap（jobname->endtime, jobid->jobname）要逻辑清楚，第三点就是前k个最长运行时间要考虑会有followup优化（堆），第四点就是写程序的风格要好（楼主面试的时候由于懒直接用h1 h2命名hashmap用o命名output函数用p命名parselog函数结果收到了小哥严肃的批评）。

parse log, a stream of log file like

[started jobname jobId]
started download 321
started download 4rdsd
started upload 3213
started transfer fdsX1

[ended jobId time]
ended 321  1342
ended 4rdsd 321
ended 3213 123
ended fdsX1 421


一个job可以run多次，每次有一个jobId. 每个jobId 需要不同的时间来完成。每个job只算最长一次的时间，问怎么求出top K job的jobId.


比如上面如果 k=2
应该返回
download 321
transfer   fdsX1


楼主先定义一个 Job class. Job class 有 jobName, jobId, time. 然后来一个priorityqueue 并且按照time排序。先把所有job读入heap中， 然后再从heap中读取k个不同的job, 这里注意 如果两个job 有同一个jobName 要dedup. 


class Solution {
public:
	class Compare {
	public:
		bool operator()(pair<string, int> a, pair<string, int> b) {
			return a.second<b.second;
		}
	};

	vector<string> getKLongestJobs(int k) {
		ifstream ifs("./job.log");
		string line;
		map<string, int> jobsTime;
		map<string, string> jobsId;
		while (getline(ifs, line)) {
			istringstream iss(line);
			string type;
			getline(iss, type, ' ');
			if (type=="started") {
				string name;
				getline(iss, name, ' ');
				string jobid;
				getline(iss, jobid, ' ');
				jobsId[jobid]=name;
			} else if (type=="ended") {
				string jobid;
				getline(iss, jobid, ' ');
				string time;
				getline(iss, time, ' ');
				int jobtime=stoi(time);
				string name=jobsId[jobid];
				if (jobsTime[name]<jobtime) {
					jobsTime[name]=jobtime;
				}
			} else {
				cerr << "incorrect format" << endl;
			}
		}

		priority_queue<pair<string, int>, vector<pair<string,int> >, Compare > pq;
		vector<string> res;
		for (auto j:jobsTime) {
			pq.push(j);
		}

		while (!pq.empty() && k>0) {
			pair<string, int> t=pq.top();
			res.push_back(t.first);
			pq.pop();
			k--;
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<string> res=s.getKLongestJobs(2);
	for (auto str:res) {
		cout << str << " ";
	}
	cout << endl;

	return 0;
}

