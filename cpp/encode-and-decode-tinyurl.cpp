535. Encode and Decode TinyURL Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 7332
Total Submissions: 9877
Difficulty: Medium
Contributor: LeetCode
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Subscribe to see which companies asked this question.

Hide Tags Hash Table Math
Hide Similar Problems (M) Design TinyURL

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        unsigned int id=hash<string>{}(longUrl);
        data[id]=longUrl;
        string res;
        while (id>0) {
            res+=letter[id%62];
            id/=62;
        }
        
        reverse(res.begin(), res.end());
        return  "http://"+res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        unsigned int id=0;
        string header="http://";
        for (int i=header.size(); i<shortUrl.size(); i++) {
            id*=62;
            if (shortUrl[i]>='a' && shortUrl[i]<='z') id+=shortUrl[i]-'a';
            else if (shortUrl[i]>='A' && shortUrl[i]<='Z') id+=shortUrl[i]-'A'+26;
            else if (shortUrl[i]>='0' && shortUrl[i]<='9') id+=shortUrl[i]-'0'+52;
        }

        return data[id];
    }
private:
    unordered_map<unsigned int,string> data;
    const string letter="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

