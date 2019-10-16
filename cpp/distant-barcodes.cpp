1054. Distant Barcodes
Medium

166

11

Favorite

Share
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]
 

Note:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size(), i=0;
        vector<int> res(n);
        unordered_map<int,int> mp;
        int maxCnt=0, maxVal;
        for (auto& b:barcodes) {
            mp[b]++;
            if (mp[b]>maxCnt) {
                maxCnt=mp[b];
                maxVal=b;
            }
        }
        
        mp.erase(maxVal);
        for (int j=0; j<maxCnt; ++j, i+=2) res[i]=maxVal;
        for (auto iter:mp) {
            for (int j=0; j<iter.second; ++j) {
                if (i>=n) i=1;
                res[i]=iter.first;
                i+=2;                
            }
        }
        
        return res;
    }
};
