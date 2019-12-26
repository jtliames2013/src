340. Longest Substring with At Most K Distinct Characters  
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

Hide Company Tags Google
Hide Tags Hash Table String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters

1. use map
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res=0, start=0, n=s.size();
        unordered_map<char,int> mp;
        for (int i=0; i<n; i++) {
            mp[s[i]]=i;
            if (mp.size()>k) {
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

2. use array
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res=0, start=0, num=0, n=s.size();
        int count[256]={0};
        for (int i=0; i<n; i++) {
            count[s[i]]++;
            if (count[s[i]]==1) num++;
            
            if (num>k) {
                res=max(res, i-start);
                while (--count[s[start]]>0) start++;
                num--;
                start++;
            }
        }
        res=max(res, n-start);
        
        return res;
    }
};

