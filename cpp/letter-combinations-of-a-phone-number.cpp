17. Letter Combinations of a Phone Number 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Hide Company Tags Amazon Dropbox Google Uber Facebook
Hide Tags Backtracking String
Show Similar Problems

class Solution {
public:
    char getbase(char digit) {
        switch(digit) {
            case '2': return 'a';
            case '3': return 'd';
            case '4': return 'g';
            case '5': return 'j';
            case '6': return 'm';
            case '7': return 'p';
            case '8': return 't';
            case '9': return 'w';
            default: return '\0';
        }
    }
    
    bool istop(char c) {
        if (c=='c' || c=='f' || c=='i' || c=='l' ||
            c=='o' || c=='s' || c=='v' || c=='z') {
                return true;
            } else {
                return false;
            }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string output;
        std::remove(digits.begin(), digits.end(), '0');
        std::remove(digits.begin(), digits.end(), '1');
        int size=digits.size();
        int i;
        for (i=0; i<size; i++) {
            output.push_back(getbase(digits[i]));
        }
        
        i=0;
        while (1) {
            if (i==output.size()) break;
            res.push_back(output);
            
            if (!istop(output[i])) output[i]++;
            else {
                while (i<output.size()) {
                    if (!istop(output[i])) break;
                    i++;
                }
                
                if (i<output.size()) {
                    output[i]++;
                    for (int j=0; j<i; j++) {
                        output[j]=getbase(digits[j]);
                    }
                    i=0;
                }
            }
        }
        
        return res;
    }
};

2. Use recursion
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string output;
        if (digits.empty()) return res;
        dfs(digits, res, output, 0);
        return res;
    }

private:
    void dfs(string digits, vector<string>& res, string& output, int start) {
        if (start==digits.size()) {
            res.push_back(output);
            return;
        }

        for (auto c:mp[digits[start]]) {
            output.push_back(c);
            dfs(digits, res, output, start+1);
            output.pop_back();
        }
    }

    unordered_map<char, vector<char>> mp={
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
};

