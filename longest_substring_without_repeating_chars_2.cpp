class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int size=s.size();
        int start=0, end=0;
        for (end=0; end<size; end++) {
            for (int i=start; i<end; i++) {
                if (s[i]==s[end]) {
                    start=i+1;
                    break;
                }
            }
            res=max(res, end-start+1);
        }

        return res;
    }
};
