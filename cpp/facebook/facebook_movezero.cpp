Move non-zeros to the left side in array, return the count of non-zero integers, don't care about the rest of the array which are not used, require minimum number of writes. Order of integers does not matter.

e.g.[1,0,2,0,4,0,5,7] -> [1,7,2,5,4,x,x,x] and return 5. # writes is 2

class Solution {
public:
	int movezero(vector<int>& nums) {
		int n=nums.size();
		int l=0, r=n-1;
		while (l<=r) {
			if (nums[r]==0) r--;
			else if (nums[l]!=0) l++;
			else {
				swap(nums[l++], nums[r--]);
			}
		}
		return l;
	}
};

void print(vector<int> n) {
	for (int i=0; i<n.size(); i++) {
		cout << n[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> n1={1,0,2,0,4,0,5,7};
	vector<int> n2={0};
	vector<int> n3={1};
	vector<int> n4={0,0,0};
	vector<int> n5={1,1,1};
	vector<int> n6={0,0,1};
	Solution s;
	cout << s.movezero(n1) << endl;
	print(n1);
	cout << s.movezero(n2) << endl;
	print(n2);
	cout << s.movezero(n3) << endl;
	print(n3);
	cout << s.movezero(n4) << endl;
	print(n4);
	cout << s.movezero(n5) << endl;
	print(n5);
	cout << s.movezero(n6) << endl;
	print(n6);

	return 0;
}

