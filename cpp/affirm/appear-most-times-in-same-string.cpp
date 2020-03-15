1. input is a list of strings, output is a map. The map key is each character appeared in the list of strings. The map value is a list of characters that appears the most times with the key characer in all of the strings. If one character appears multiple times in the same string, counts as 1.
Example:
input: ['abc', 'bcd', 'cde', 'def']
output:
{
a:[b, c],
b: [c],
c: [b, d],
e: [d],
f: [d, e]
}

2. write two functions, addWord, printValue

class Solution {
public:
    void addWord(string word) {
        unordered_set<char> st(word.begin(), word.end());
        for (auto ch1:st) {
            for (auto ch2:st) {
                if (ch1!=ch2) {
                    mp[ch1][ch2]++;
                    mp[ch2][ch1]++;
                }
            }
        }
    }

    void printValue() {
        for (auto iter:mp) {
            cout << iter.first << ": {";
            unordered_set<char> st;
            int maxCount=0;
            for (auto iter2:iter.second) {
                if (iter2.second>maxCount) {
                    st.clear();
                    st.insert(iter2.first);
                    maxCount=iter2.second;
                } else if (iter2.second==maxCount) {
                    st.insert(iter2.first);
                }
            }
            for (auto ch:st) cout << ch << " ";
            cout << "}" << endl;
        }
    }
private:
    unordered_map<char, unordered_map<char, int>> mp;
};

int main(int argc, char** argv) {
    Solution s;
    s.addWord("abc");
    s.addWord("bcd");
    s.addWord("cde");
    s.addWord("def");
    s.printValue();
    return 0;
}

