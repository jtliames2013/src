给了一串task，不同的task可能属于不同type。这些task要放到CPU里运行，运行同一种type是要考虑一个冷却时间。
举个栗子：thread是1,2,3,1不能改顺序， 冷却时间3，运行起来就是1, 2, 3, _, 1时间就是5.要返回总运行时间5
我是用hashmap，key是该task的数字，value是上次运行这个task的时间。
follow up是如果可以改变顺序，最少要运行多少时间

每种task都有冷却时间，比如task1执行后，要经过interval时间后才能再次执行，求总共所需时间。
Sample 1 
tasks: 1, 1, 2, 1.  recovery interval: 2
output: 7  (order is 1 _ _ 1 2 _ 1)

Sample 2
tasks: 1, 2, 3, 1, 2, 3.  recovery interval: 3
output: 7  (order is 1 2 3 _ 1 2 3)

class Solution {
public:
	  int getTime(vector<int> samples, int interval) {
		  int total=0;
		  map<int, int> lastTime;
		  for (int i=0; i<samples.size(); i++) {
			  if (lastTime.find(samples[i])==lastTime.end()) {
				  lastTime[samples[i]]=total;
				  total++;
			  } else {
				  if (total-1-lastTime[samples[i]]<interval) {
					  // there are interval numbers in between excluding start and end
					  total=lastTime[samples[i]]+interval+1;
					  lastTime[samples[i]]=total;
					  total++;
				  } else {
					  lastTime[samples[i]]=total;
					  total++;
				  }
			  }
		  }

		  return total;
	  }
  };

2.
class Solution {
public:
	  int getTime(vector<int> samples, int interval) {
		  int total=0;
		  map<int, int> lastTime;
		  for (int i=0; i<samples.size(); i++) {
			  if (lastTime.find(samples[i])!=lastTime.end() && total-1-lastTime[samples[i]]<interval) {
				  // there are interval numbers in between excluding start and end
				  total=lastTime[samples[i]]+interval+1;
			  }

			  lastTime[samples[i]]=total;
			  total++;
		  }

		  return total;
	  }
  };

3. minimize time if the order of tasks can be changed
 /**
     * Follow up:
     * Find the task that appears for the most time
     * Use a map to count the number of the times the task appears  then get the maximum count.
     * the result is decided by the maximum count and the number of tasks with maximum count
     *
     * two conditions:
     * 1.  5 4 _ _ _ 5 4 _ _ _ 5 4 _ _ _ 5 4  the rest tasks cannot fill the empty slots
     *     5 4 3 2 _ 5 4 3 2 _ 5 4 _ _ _ 5 4
     *     the answer is (maxCount - 1) * (interval + 1) + CountOfMax
     * 1. 5 4 _ _ _ 5 4 _ _ _ 5 4 _ _ _ 5 4  the rest tasks cannot fill the empty slots
     *    5 4 3 2 1 6 5 4 3 2 1 6 5 4 6 _ _ 5 4
     *    the answer is the length of the nums
     *    the task which does not have max count first fills the empty slots and then just insert any valid place
     * */
  class Solution {
  public:
  	  int getTime(vector<int> samples, int interval) {
  		  map<int, int> count;
  		  int maxCnt=0, numMax;
  		  for (auto s:samples) {
  			  count[s]++;
  			  if (maxCnt<count[s]) {
  				  maxCnt=count[s];
  				  numMax=1;
  			  } else if (maxCnt==count[s]) {
  				  numMax++;
  			  }
  		  }

  		  return max((int)samples.size(), (maxCnt-1)*(interval+1)+numMax);
  	  }
    };

class Solution {
public:
	  int getTime(vector<int> samples, int interval) {
		  map<int, int> count;
		  map<int, int> lastTime;
		  for (auto s:samples) count[s]++;
		  vector<pair<int, int> > v;
		  for (auto c:count) v.push_back({c.first, c.second});
		  sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {return a.second>b.second;} );

		  int total=0;
		  while (v.size()>0) {
			  for (auto iter=v.begin(); iter<v.end(); iter++) {
				  if (lastTime.find(iter->first)!=lastTime.end() &&
					  total<lastTime[iter->first]+interval+1) {
					  total=lastTime[iter->first]+interval+1;
				  }
				  lastTime[iter->first]=total;
				  total++;
				  iter->second--;
				  if (iter->second==0) v.erase(iter);
			  }
		  }

		  return total;
	  }
  };



int main()
{
	Solution s;
	vector<int> samples={1,2,3,1,2,3};
	int res=s.getTime(samples, 3);
	cout << res << endl;
	return 0;
}

