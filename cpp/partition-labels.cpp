763. Partition Labels
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> pos(26);
        for (int i=0; i<S.size(); i++) pos[S[i]-'a']=i;
        
        int start=0, end=0;
        for (int i=0; i<S.size(); i++) {
            end=max(end, pos[S[i]-'a']);
            if (end==i) {
                res.push_back(end-start+1);
                start=end=i+1;
            }
        }
        
        return res;
    }
};
