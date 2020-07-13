1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits
Hard

109

11

Add to List

Share
Given a string num representing the digits of a very large integer and an integer k.

You are allowed to swap any two adjacent digits of the integer at most k times.

Return the minimum integer you can obtain also as a string.

 

Example 1:


Input: num = "4321", k = 4
Output: "1342"
Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
Example 2:

Input: num = "100", k = 1
Output: "010"
Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
Example 3:

Input: num = "36789", k = 1000
Output: "36789"
Explanation: We can keep the number without any swaps.
Example 4:

Input: num = "22", k = 22
Output: "22"
Example 5:

Input: num = "9438957234785635408", k = 23
Output: "0345989723478563548"
 

Constraints:

1 <= num.length <= 30000
num contains digits only and doesn't have leading zeros.
1 <= k <= 10^9

1. TLE
class Solution {
public:
    string minInteger(string num, int k) {
        int n=num.size();
        if (k<=0) return num;
        if (k>=n*(n+1)/2) {
            sort(num.begin(), num.end());
            return num;
        }
        for (int i=0; i<10; ++i) {
            int pos=num.find(i+'0');
            if (pos>=0 && pos<=k) {
                return num[pos]+minInteger(num.substr(0, pos)+num.substr(pos+1), k-pos);
            }
        }
        return num;
    }
};

2. BIT
class BIT {
public:
    BIT(int n) {
        idx.resize(n+1);
    }

    void update(int i, int delta) {
        int n=idx.size();
        while (i<n) {
            idx[i]+=delta;
            i+=(i&-i);
        }
    }

    int query(int i) {
        int res=0;
        while (i>0) {
            res+=idx[i];
            i-=(i&-i);
        }
        return res;
    }
private:
    vector<int> idx;
};

class Solution {
public:
    string minInteger(string num, int k) {
        string res;
        int n=num.size();
        vector<vector<int>> pos(10);
        for (int i=n-1; i>=0; --i) {
            pos[num[i]-'0'].push_back(i);
        }

        BIT bit(n);
        vector<int> selected;
        vector<bool> removed(n);
        while (k>0) {
            int idx=-1, dist, digit=0;
            for (; digit<10; ++digit) {
                if (pos[digit].empty()) continue;
                idx=pos[digit].back();
                dist=idx-bit.query(idx);
                if (dist<=k) break;
            }
            if (idx==-1) break;
            k-=dist;
            pos[digit].pop_back();
            selected.push_back(digit);
            removed[idx]=true;
            bit.update(idx+1, 1);
        }
        for (auto i:selected) res+=i+'0';
        for (int i=0; i<n; ++i) {
            if (!removed[i]) res+=num[i];
        }
        return res;
    }
};


