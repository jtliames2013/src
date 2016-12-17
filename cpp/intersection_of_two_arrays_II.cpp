class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i1=0, i2=0, n1=nums1.size(), n2=nums2.size();
        for (; i1<n1 && i2<n2;) {
            if (nums1[i1]<nums2[i2]) i1++;
            else if (nums1[i1]>nums2[i2]) i2++;
            else {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }
        return res;
    }
};

2.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) return intersect(nums2, nums1);
        vector<int> res;
        map<int,int> count1;
        for (int i:nums1) count1[i]++;
        for (int i:nums2) {
            if (count1[i]>0) {
                res.push_back(i);
                count1[i]--;
            }
        }
        return res;
    }
};

