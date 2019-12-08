1239. Maximum Length of a Concatenated String with Unique Characters
Medium

98

18

Favorite

Share
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res=0;
        vector<int> st={0};
        for (auto& s:arr) {
            int key=0;
            bool cont=false;
            for (auto c:s) {
                if ((key & (1<<(c-'a')))>0) {
                    cont=true;
                    break;
                }
                key|=(1<<(c-'a'));            
            }
            // skip if s contains duplicate
            if (cont) continue;
            
            for (int i=st.size()-1; i>=0; --i) {
                if ((st[i] & key)>0) continue;
                st.push_back((st[i] | key));
                res=max(res, bitCount((st[i] | key)));
            }
        }
        return res;
    }
private:
    int bitCount(int n) {
        int res=0;
        while (n>0) {
            n&=(n-1);
            res++;
        }
        return res;
    }
};

