966. Vowel Spellchecker
Medium

85

169

Favorite

Share
Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

Note:

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=queries.size();
        vector<string> res(n);
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;
        for (auto& w:wordlist) {
            cap.insert({lowerCase(w), w});
            vow.insert({replaceVowels(w), w});
        }
        
        for (int i=0; i<n; ++i) {
            string c=lowerCase(queries[i]), v=replaceVowels(queries[i]);
            if (st.find(queries[i])!=st.end()) res[i]=queries[i];
            else if (cap.find(c)!=cap.end()) res[i]=cap[c];
            else if (vow.find(v)!=vow.end()) res[i]=vow[v];
        }
        return res;
    }
private:
    string lowerCase(string s) {
        for (auto& c:s) c=tolower(c);
        return s;
    }
    
    string replaceVowels(string s) {
        s=lowerCase(s);
        for (auto& c:s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c='*';
        }
        return s;
    }
};
