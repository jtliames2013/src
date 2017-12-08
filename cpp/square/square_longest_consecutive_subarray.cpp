电面：
1. 给一个数组，找出一个长度最长的子数组，里面的值是连续的。
Follow up:
  连续的值可以跳着的，不一定index也是连续，返回这种子序列的最大长度

class Solution {
public:
	int longestConsecutiveSubarray(vector<int>& nums) {
		int n=nums.size();
		int longest=0;
		for (int i=0; i<n; ) {
			int incIdx=i+1;
			while (incIdx<n && nums[incIdx]==nums[incIdx-1]+1) {
				incIdx++;
			}
			longest=max(longest, incIdx-i);
			int decIdx=i+1;
			while (decIdx<n && nums[decIdx]==nums[decIdx-1]-1) {
				decIdx++;
			}
			longest=max(longest, decIdx-i);
			i=max(incIdx, decIdx);
		}

		return longest;
	}
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> st;
        for (auto n:nums) st.insert(n);
        
        while (!st.empty()) {
            int num=*st.begin();
            int l=num, r=num;
            st.erase(num);
            
            while (1) {
                l--;
                if (st.find(l)==st.end()) break;
                st.erase(l);
            }
            
            while (1) {
                r++;
                if (st.find(r)==st.end()) break;
                st.erase(r);
            }
            
            longest=max(longest, r-l-1);
        }
        
        return longest;
    }
};

int main() {
	vector<int> nums={1,2,3,4,5,6,7};
	Solution s;
	int res=s.longestConsecutiveSubarray(nums);
	cout << res << endl;
	return 0;
}

