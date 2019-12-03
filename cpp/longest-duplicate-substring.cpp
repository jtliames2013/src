1044. Longest Duplicate Substring
Hard

139

94

Favorite

Share
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.


https://en.wikipedia.org/wiki/Rabin–Karp_algorithm
This is a tricky one on two sides:
1. how to find the length of the lonest string
2. how to compare the string of the same length
For the first point, we can use binary search for answer since if a string of length n is
invalid then for all k > n, there's definetly no solution because length n strings would 
become a substring of the length k string. Similarly if a string of length n is valid, we have
no use of checking strings with length less than n. Due to these properties we can use
binary search for final answer.
For the second point, we are actually trying to compare a sliding window of string, and
Rabin Karp algorithm is perfect for doing so. The algorithm basically computes the 
hash value of all the string and start a character by character comparison only if the two 
strings have the same hash value. In order to avoid collision we can use a large prime number
such as 1e9 + 7, 19260817, 99999989, etc.

class Solution {
public:
    string longestDupSubstring(string S) {
        string res;
        int n=S.size();
        vector<long> power(n, 1);
        for (int i=1; i<n; ++i) power[i]=power[i-1]*26%mod;
        int l=0, r=n, mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            string str=search(S, power, mid);
            if (str.empty()) {
                r=mid-1;                
            } else {
                if (str.size()>res.size()) res=str;
                l=mid+1;
            }
        }
        return res;
    }
private:
    string search(string& S, vector<long>& power, int len) {
        if (len==0) return "";
        unordered_map<int, vector<int>> hash;
        long long curr=0;
        for (int i=0; i<len; ++i) curr=((curr*26)%mod+S[i]-'a')%mod;
        
        hash[curr]={0};
        for (int i=len; i<S.size(); ++i) {
            curr=((curr-(long long)power[len-1]*(S[i-len]-'a'))%mod+mod)%mod;
            curr=(curr*26+S[i]-'a')%mod;
        
            if (hash.find(curr)==hash.end()) {
                hash[curr]={i-len+1};
            } else {
                for (auto& j:hash[curr]) {
                    if (S.substr(j, len)==S.substr(i-len+1, len)) return S.substr(j, len);
                }
                hash[curr].push_back(i-len+1);
            }            
        }
        return "";
    }
    
    const int mod=1e9+7;
};


Please check, Suffix array tutorial
https://www.geeksforgeeks.org/­­kasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
https://www.geeksforgeeks.org/suffix-array-set-1-introduction/

Given a String we build its Suffix array and LCP (longest common Prefix).
The maximum LCP is the size of longest duplicated substring.
