816. Ambiguous Coordinates
DescriptionHintsSubmissionsDiscussSolution
We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.
 

Note:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.

if S == "": return []
if S == "0": return [S]
if S == "0XXX0": return []
if S == "0XXX": return ["0.XXX"]
if S == "XXX0": return [S]
return [S, "X.XXX", "XX.XX", "XXX.X"...]

class Solution {
public:
    vector<string> helper(string s) {        
        int n=s.size();
        if (n==0) return {};
        if (n==1) return {s};
        if (s[0]=='0' && s[n-1]=='0') return {};
        else if (s[0]=='0') return {"0."+s.substr(1)};
        else if (s[n-1]=='0') return {s};
        else {
            vector<string> res={s};
            for (int i=1; i<n; ++i) {
                res.push_back(s.substr(0, i)+"."+s.substr(i));
            }
            return res;
        }
    }
    
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        int n=S.size();
        for (int i=1; i<n-2; ++i) {
            vector<string> left=helper(S.substr(1, i)), right=helper(S.substr(i+1, n-2-i));
            for (auto& l:left) {
                for (auto& r:right) {
                    res.push_back("("+l+", "+r+")");    
                }
            }
        }
        
        return res;
    }
};
