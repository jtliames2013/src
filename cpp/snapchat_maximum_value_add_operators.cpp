一个找最大值的题。给一个数组[1,1,2,1]，然后用+ * （）三个操作求出这个数组的最大值，这个题返回6。

class Solution {
public:
	  int findMaxValue(vector<int> nums) {
		  int n=nums.size();
		  if (n==0) return 0;
		  vector<vector<int> > maxVal(n, vector<int>(n,0));
		  vector<vector<int> > minVal(n, vector<int>(n,0));
		  for (int i=0; i<n; i++) {
			  maxVal[i][i]=minVal[i][i]=nums[i];
		  }

		  for (int i=0; i<n; i++) {
			  for (int j=i-1; j>=0; j--) {
				  maxVal[i][j]=INT_MIN;
				  minVal[i][j]=INT_MAX;
				  for (int k=j; k<i; k++) {
					  // max(max1+max2, max1*max2, min1*min2)
					  // min(min1+min2, min1*min2, max1*min1, min1*max1)
					  maxVal[i][j]=max(maxVal[i][j], max(maxVal[k][j]+maxVal[i][k+1], maxVal[k][j]*maxVal[i][k+1]));
					  maxVal[i][j]=max(maxVal[i][j], minVal[k][j]*minVal[i][k+1]);
					  minVal[i][j]=min(minVal[i][j], min(minVal[k][j]+minVal[i][k+1], minVal[k][j]*minVal[i][k+1]));
					  minVal[i][j]=min(minVal[i][j], min(maxVal[k][j]*minVal[i][k+1], minVal[k][j]*maxVal[i][k+1]));
				  }
			  }
		  }

		  return maxVal[n-1][0];
	  }

	  struct Entry {
		  int pos;
		  string op;
		  bool leftmax;
		  bool rightmax;
		  Entry():pos(0), op("+"), leftmax(true), rightmax(true) {}
		  Entry(int p, string c, bool l, bool r):pos(p), op(c), leftmax(l), rightmax(r) {}
	  };

	  string getExpr(vector<int>& nums, vector<vector<Entry> >& opMax, vector<vector<Entry> >& opMin, int start, int end, bool isMax) {
		  string res;
		  if (start==end) return to_string(nums[start]);

		  Entry e=isMax?opMax[end][start]:opMin[end][start];
		  res+="(" + getExpr(nums, opMax, opMin, start, e.pos, e.leftmax) + ")";
		  res+=e.op;
		  res+="(" + getExpr(nums, opMax, opMin, e.pos+1, end, e.rightmax) + ")";

		  return res;
	  }

	  string findMaxExpr(vector<int> nums) {
		  int n=nums.size();
		  if (n==0) return 0;
		  vector<vector<int> > maxVal(n, vector<int>(n,0));
		  vector<vector<int> > minVal(n, vector<int>(n,0));
		  vector<vector<Entry> > opMax(n, vector<Entry>(n));
		  vector<vector<Entry> > opMin(n, vector<Entry>(n));
		  for (int i=0; i<n; i++) {
			  maxVal[i][i]=minVal[i][i]=nums[i];
		  }

		  for (int i=0; i<n; i++) {
			  for (int j=i-1; j>=0; j--) {
				  maxVal[i][j]=INT_MIN;
				  minVal[i][j]=INT_MAX;
				  for (int k=j; k<i; k++) {
					  // max(max1+max2, max1*max2, min1*min2)
					  // min(min1+min2, min1*min2, max1*min1, min1*max1)
					  if (maxVal[i][j]<maxVal[k][j]+maxVal[i][k+1]) {
						  maxVal[i][j]=maxVal[k][j]+maxVal[i][k+1];
						  opMax[i][j]={k, "+", true, true};
					  }
					  if (maxVal[i][j]<maxVal[k][j]*maxVal[i][k+1]) {
						  maxVal[i][j]=maxVal[k][j]*maxVal[i][k+1];
						  opMax[i][j]={k, "*", true, true};
					  }
					  if (maxVal[i][j]<minVal[k][j]*minVal[i][k+1]) {
						  maxVal[i][j]= minVal[k][j]*minVal[i][k+1];
						  opMax[i][j]={k, "*", false, false};
					  }

					  if (minVal[i][j]>minVal[k][j]+minVal[i][k+1]){
						  minVal[i][j]=minVal[k][j]+minVal[i][k+1];
						  opMin[i][j]={k, "+", false, false};
					  }
					  if (minVal[i][j]> minVal[k][j]*minVal[i][k+1]){
						  minVal[i][j]=minVal[k][j]*minVal[i][k+1];
						  opMin[i][j]={k, "*", false, false};
					  }
					  if (minVal[i][j]>maxVal[k][j]*minVal[i][k+1]) {
						  minVal[i][j]=maxVal[k][j]*minVal[i][k+1];
						  opMin[i][j]={k, "*", true, false};
					  }
					  if (minVal[i][j]>minVal[k][j]*maxVal[i][k+1]) {
						  minVal[i][j]=minVal[k][j]*maxVal[i][k+1];
						  opMin[i][j]={k, "*", false, true};
					  }
				  }
			  }
		  }

		  return getExpr(nums, opMax, opMin, 0, nums.size()-1, true);
	  }
  };

int main() {
	Solution s;
	//vector<int> nums={1,2,3,4};
	vector<int> nums={-3, 2, -2, 1};
	//vector<int> nums={1, 1, 2, 1};
	int res=s.findMaxValue(nums);
	string expr=s.findMaxExpr(nums);
	return 0;
}

