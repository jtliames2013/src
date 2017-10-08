 Program to return the index of the maximum number in the array [ To Note : the array may or may not contain multiple copies of maximum number ] such that each index ( which contains the maximum numbers ) have the probability of 1/no of max numbers to be returned.

example [-1 3 2 3 3] , each of [1,3,4] have the probability 1/3 to be returned. [ 2 4 6 6 3 1 6 6 ] , each of [2,3,6,7] have the probability of 1/4 to be returned.

class Solution {
public:
	  int randomMaxIndex(vector<int>& nums) {
		  if (nums.size()==0) return -1;
		  int maxNum=nums[0], maxIdx=0, maxCnt=1;
		  for (int i=1; i<nums.size(); i++) {
			  if (nums[i]>maxNum) {
				  maxNum=nums[i];
				  maxIdx=i;
				  maxCnt=1;
			  } else (nums[i]==maxNum) {
				  maxCnt++;
				  if (rand()%maxCnt==0) maxIdx=i;
			  }
		  }
		  return maxIdx;
	  }
  };

2.
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

