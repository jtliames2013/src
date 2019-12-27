1181. Before and After Puzzle
Medium

32

70

Add to List

Share
Given a list of phrases, generate a list of Before and After puzzles.

A phrase is a string that consists of lowercase English letters and spaces only. No space appears in the start or the end of a phrase. There are no consecutive spaces in a phrase.

Before and After puzzles are phrases that are formed by merging two phrases where the last word of the first phrase is the same as the first word of the second phrase.

Return the Before and After puzzles that can be formed by every two phrases phrases[i] and phrases[j] where i != j. Note that the order of matching two phrases matters, we want to consider both orders.

You should return a list of distinct strings sorted lexicographically.

 

Example 1:

Input: phrases = ["writing code","code rocks"]
Output: ["writing code rocks"]
Example 2:

Input: phrases = ["mission statement",
                  "a quick bite to eat",
                  "a chip off the old block",
                  "chocolate bar",
                  "mission impossible",
                  "a man on a mission",
                  "block party",
                  "eat my words",
                  "bar of soap"]
Output: ["a chip off the old block party",
         "a man on a mission impossible",
         "a man on a mission statement",
         "a quick bite to eat my words",
         "chocolate bar of soap"]
Example 3:

Input: phrases = ["a","b","a"]
Output: ["a"]
 

Constraints:

1 <= phrases.length <= 100
1 <= phrases[i].length <= 100
Accepted
4,701
Submissions
10,691

clutter
|
LeetCode

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        set<string> st;
        unordered_map<string, unordered_set<string>> first, last;
        for (auto& p:phrases) {
            auto pos=p.find_first_of(' ');
            string firstWord, firstOther;
            if (pos==string::npos) {
                firstWord=p;
            } else {
                firstWord=p.substr(0, pos);
                firstOther=p.substr(pos);
            }
            for (auto& s:last[firstWord]) st.insert(s+firstOther); 
            
            pos=p.find_last_of(' ');
            string lastWord;
            if (pos==string::npos) lastWord=p;
            else lastWord=p.substr(pos+1);            
            for (auto& s:first[lastWord]) st.insert(p+s);
            
            first[firstWord].insert(firstOther);
            last[lastWord].insert(p);
        }
        
        return vector<string>(st.begin(), st.end());
    }
};

