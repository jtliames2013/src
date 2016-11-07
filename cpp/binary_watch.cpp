401. Binary Watch   QuestionEditorial Solution  My Submissions
Total Accepted: 11301 Total Submissions: 26221 Difficulty: Easy Contributors: Admin
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

Subscribe to see which companies asked this question

Hide Tags Backtracking Bit Manipulation
Hide Similar Problems (M) Letter Combinations of a Phone Number (E) Number of 1 Bits

class Solution {
public:
    vector<string> getHour(int h) {
        vector<string> res;
        for (int i=0; i<12; i++) {
            int count=0;
            int n=i;
            while (n>0) {
                if ((n & 0x1)==1) count++;
                n>>=1;
            }
            if (count==h) res.push_back(to_string(i));
        }
        return res;
    }
    vector<string> getMinute(int m) {
        vector<string> res;
        for (int i=0; i<60; i++) {
            int count=0;
            int n=i;
            while (n>0) {
                if ((n & 0x1)==1) count++;
                n>>=1;
            }
            if (count==m) {
                string str=to_string(i);
                if (i<10) str="0"+str;
                res.push_back(str);
            }
        }
        return res;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num<0||num>9) return res;
        for (int h=0; h<=num && h<=3; h++) {
            int m=num-h;
            vector<string> hours=getHour(h);
            vector<string> mins=getMinute(m);
            for (int i=0; i<hours.size(); i++) {
                for (int j=0; j<mins.size(); j++) {
                    res.push_back(hours[i]+":"+mins[j]);
                }
            }
        }
        
        return res;
    }
};

2.
class Solution {
public:
    vector<int> getNum(int n, vector<int>& nums) {
        vector<int> res;
        int sum=0;
        dfs(res, n, sum, nums, 0);
        return res;
    }
    void dfs(vector<int>& res, int n, int& sum, vector<int>& nums, int start) {
        if (n==0) {
            res.push_back(sum);
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            sum+=nums[i];
            dfs(res, n-1, sum, nums, i+1);
            sum-=nums[i];
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num<0||num>9) return res;
        vector<int> nums1={8,4,2,1};
        vector<int> nums2={32,16,8,4,2,1};
        for (int h=0; h<=num && h<=3; h++) {
            int m=num-h;
            vector<int> hours=getNum(h, nums1);
            vector<int> mins=getNum(m, nums2);
            for (int i=0; i<hours.size(); i++) {
                if (hours[i]>=12) continue;
                for (int j=0; j<mins.size(); j++) {
                    if (mins[j]>=60) continue;
                    string str=to_string(mins[j]);
                    if (mins[j]<10) str="0"+str;
                    res.push_back(to_string(hours[i])+":"+str);
                }
            }
        }
        
        return res;
    }
};

