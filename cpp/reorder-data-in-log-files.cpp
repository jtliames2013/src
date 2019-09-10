937. Reorder Data in Log Files
Easy

229

676

Favorite

Share
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
    
    static bool compare(string a, string b) {
        int i=a.find_first_of(' ');
        int j=b.find_first_of(' ');
        if (!isdigit(a[i+1]) && !isdigit(b[j+1])) {
            return a.substr(i+1)<b.substr(j+1) || (a.substr(i+1)==b.substr(j+1) && a.substr(0,i)<b.substr(0,j));
        } else if (!isdigit(a[i+1])) {
            return true;
        } else {
            return false;
        }
    }
};
