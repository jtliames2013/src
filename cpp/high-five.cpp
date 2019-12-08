1086. High Five
Easy

97

26

Favorite

Share
Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Goldman Sachs
|
8

Amazon
|
4

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        map<int, priority_queue<int>> mp;
        for (auto& item:items) mp[item[0]].push(item[1]);
        for (auto iter:mp) {
            int sum=0, k=5;
            while (k-- > 0) {
                sum+=iter.second.top();
                iter.second.pop();                
            }
            res.push_back({iter.first, sum/5});
        }
        
        return res;
    }
};

