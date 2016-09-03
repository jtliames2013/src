class Solution {

public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;

        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());

        int i=0, j=0, n1=nums1.size(), n2=nums2.size();

        while (i<n1 && j<n2) {

            if (nums1[i]<nums2[j]) i++;

            else if (nums1[i]>nums2[j]) j++;

            else {

                int inter=nums1[i];

                int k1=0, k2=0;

                while (nums1[i]==inter) { i++; k1++; }

                while (nums2[j]==inter) { j++; k2++; }

                int k=min(k1, k2);

                while (k>0) { k--; res.push_back(inter); }

             }

        }

        

        return res;

    }

};
