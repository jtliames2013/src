551. Student Attendance Record I Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 6808
Total Submissions: 15425
Difficulty: Easy
Contributors:
fallcreek
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
Subscribe to see which companies asked this question.

Hide Tags String
Hide Similar Problems (H) Student Attendance Record II

class Solution {
public:
    bool checkRecord(string s) {
        int a=0, l=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='A') a++;
            if (s[i]=='L') l++;
            else l=0;
            if (a>1 || l>2) return false;
        }
        return true;
    }
};

