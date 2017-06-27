159. Longest Substring with At Most Two Distinct Characters  
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.

Hide Company Tags Google
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (M) Longest Substring Without Repeating Characters (H) Sliding Window Maximum (H) Longest Substring with At Most K Distinct Characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res=0, start=0, n=s.size();
        unordered_map<char,int> mp;
        for (int i=0; i<n; i++) {
            mp[s[i]]=i;
            if (mp.size()>2) {
                res=max(res, i-start);
                int idx=INT_MAX;
                char ch;
                for (auto& iter:mp) {
                    if (iter.second<idx) {
                        idx=iter.second;
                        ch=iter.first;
                    }    
                }
                mp.erase(ch);
                start=idx+1;
            }
        }
        res=max(res, n-start);
        
        return res;
    }
};

