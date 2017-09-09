class Solution {
public:
	int getRandomMaximalElementsIndex(vector<int> data) {
		if (data.size()==0) return -1;
		int maxValue=data[0], maxIndex=0, count=1;
		srand (time(NULL));
		for (int i=1; i<data.size(); i++) {
			if (maxValue<data[i]) {
				maxValue=data[i];
				maxIndex=i;
				count=1;
			} else if (maxValue==data[i]) {
				count++;
				if (rand() < ((double)RAND_MAX)/count) {
					maxIndex=i;
				}
			}
		}

		return maxIndex;
	}
};

int main() {
	Solution s;
	vector<int> data={1,2,3,3,3,2,1,1,1};
	int res=s.getRandomMaximalElementsIndex(data);
	cout << res << endl;
	return 0;
}

