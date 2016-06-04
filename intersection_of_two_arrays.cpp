class Solution {

public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;

        int size1=nums1.size();

        int size2=nums2.size();

        if (size1==0 || size2==0) return res;

        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());

        

        int i=0, j=0;

        while (i<size1 && j<size2) {

            if (nums1[i]<nums2[j]) {

                i++;

            } else if (nums1[i]>nums2[j]) {

                j++;

            } else {

                int inter=nums1[i];

                res.push_back(inter);

                while (i<size1 && nums1[i]==inter) i++;

                while (j<size2 && nums2[j]==inter) j++;

            }

        }

        

        return res;

    }

};
