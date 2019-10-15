670. Maximum Swap
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        vector<int> pos(10);
        for (int i=0; i<str.size(); ++i) {
            pos[str[i]-'0']=i;
        }
        for (int i=0; i<str.size(); ++i) {
            for (int k=9; k>str[i]-'0'; --k) {
                if (pos[k]>i) {
                    swap(str[i], str[pos[k]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};
