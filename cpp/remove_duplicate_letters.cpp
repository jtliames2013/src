316. Remove Duplicate Letters 
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char,int> count;
        unordered_set<char> visited;
        for (auto c:s) count[c]++;
        
        for (auto c:s) {
            count[c]--;
            if (visited.find(c)==visited.end()) {
                while (!res.empty() && c<res.back() && count[res.back()]>0) {
                    visited.erase(res.back());
                    res.pop_back();
                }
                res.push_back(c);
                visited.insert(c);
            }
        }
        return res;
    }
};

2. Use array to look up
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        vector<char> count(256);
        vector<bool> visited(256);
        for (auto c:s) count[c]++;
        
        for (auto c:s) {
            count[c]--;
            if (visited[c]==false) {
                while (!res.empty() && c<res.back() && count[res.back()]>0) {
                    visited[res.back()]=false;
                    res.pop_back();
                }
                res.push_back(c);
                visited[c]=true;
            }
        }
        return res;
    }
};
