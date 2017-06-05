599. Minimum Index Sum of Two Lists
DescriptionHintsSubmissionsSolutions
Total Accepted: 4708
Total Submissions: 9167
Difficulty: Easy
Contributors:
love_Fawn
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
Subscribe to see which companies asked this question.

Hide Tags Hash Table
Hide Similar Problems (E) Intersection of Two Linked Lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,int> mp;
        int minCnt=INT_MAX;
        for (int i=0; i<list1.size(); i++) mp[list1[i]]=i;
        for (int i=0; i<list2.size(); i++) {
            if (mp.find(list2[i])!=mp.end()) {
                int cnt=i+mp[list2[i]];
                if (cnt<minCnt) {
                    res.clear();
                    res.push_back(list2[i]);
                    minCnt=cnt;
                } else if (cnt==minCnt) {
                    res.push_back(list2[i]);
                }
            }
        }

        return res;
    }
};

