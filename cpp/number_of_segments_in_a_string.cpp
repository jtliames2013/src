434. Number of Segments in a String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 3894
Total Submissions: 10048
Difficulty: Easy
Contributors: love_FDU_llp
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
Subscribe to see which companies asked this question

Hide Tags String

class Solution {
public:
    int countSegments(string s) {
        int res=0;
        for (int i=0; i<s.size();) {
            if (s[i]==' ') i++;
            else {
                res++;
                while (i<s.size() && s[i]!=' ') i++;
            }
        } 
        return res;
    }
};

