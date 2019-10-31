899. Orderly Queue
Hard

126

154

Favorite

Share
A string S of lowercase letters is given.  Then, we may make any number of moves.

In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.

Return the lexicographically smallest string we could have after any number of moves.

 

Example 1:

Input: S = "cba", K = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
Example 2:

Input: S = "baaca", K = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
 

Note:

1 <= K <= S.length <= 1000
S consists of lowercase letters only.

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K>1) {
            sort(S.begin(), S.end());
            return S;
        }
        
        string res=S;
        for (int i=1; i<S.size(); ++i) {
            res=min(res, S.substr(i)+S.substr(0,i));
        }
        return res;
    }
};
