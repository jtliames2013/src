1360. Number of Days Between Two Dates
Easy

1

10

Add to List

Share
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

 

Example 1:

Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1
Example 2:

Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(daysSince1970(date1)-daysSince1970(date2));
  }
private:
    int daysSince1970(string date) {
        int res=0, y=stoi(date.substr(0,4)), m=stoi(date.substr(5,2)), d=stoi(date.substr(8,2));
        for (int i=1970; i<y; ++i) {
            res+=365;
            bool leap=(i%400==0 || (i%4==0 && i%100!=0));
            if (leap) res++;
        }

        bool leap=(y%400==0 || (y%4==0 && y%100!=0));
        for (int i=0; i<m-1; ++i) {
            res+=days[i];
            if (i==1 && leap) res++;
        }
        res+=d;
        return res;
    }

    const int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

