在一个nonnegative array里找continuous sequence 加起来等于特定值的一道题

class Solution {
public:
    int SubArraySum(int s, vector<int>& nums) {
        if (s<0) return false;
        int n=nums.size(), l=0, r=0;
        int sum=0;
        for (; r<n; r++) {
            sum+=nums[r];
            while (sum>s) {
                sum-=nums[l];
                l++;
            }
            if (sum==s) return true;
        }
        
        return false;
    }
};

if array has negative
class Solution {
public:
    int SubArraySum(int s, vector<int>& nums) {
    	unordered_set<int> st;
    	st.insert(0);
    	int sum=0;
    	for (auto n:nums) {
    		sum+=n;
    		if (st.find(sum-s)!=st.end()) return true;
    		st.insert(sum);
    	}

        return false;
    }
};

if subarray size > 1
class Solution {
public:
    int SubArraySum(int s, vector<int>& nums) {
    	unordered_map<int, int> mp;
    	mp[0]=-1;
    	int sum=0;
    	for (int i=0; i<nums.size(); i++) {
    		sum+=nums[i];
    		if (mp.find(sum-s)!=mp.end()) {
    			if (i-mp[sum-s]>1) return true;
    		} else {
    			mp[sum]=i;
    		}

    	}

        return false;
    }
};

