1152. Analyze User Website Visit Pattern
Medium

20

146

Add to List

Share
We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].

A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence are not necessarily distinct.)

Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.

 

Example 1:

Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
 

Note:

3 <= N = username.length = timestamp.length = website.length <= 50
1 <= username[i].length <= 10
0 <= timestamp[i] <= 10^9
1 <= website[i].length <= 10
Both username[i] and website[i] contain only lowercase characters.
It is guaranteed that there is at least one user who visited at least 3 websites.
No user visits two websites at the same time.

Amazon
|
4

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        string res;
        int maxCount=0;
        unordered_map<string, map<int, string>> mp;
        unordered_map<string, int> count;
        for (int i=0; i<username.size(); ++i) mp[username[i]][timestamp[i]]=website[i];
        
        for (auto& iter:mp) {
            unordered_set<string> st;
            for (auto it1=iter.second.begin(); it1!=iter.second.end(); ++it1) {
                for (auto it2=next(it1); it2!=iter.second.end(); ++it2) {
                    for (auto it3=next(it2); it3!=iter.second.end(); ++it3) {
                        st.insert(it1->second+","+it2->second+","+it3->second);
                    }
                }
            }
            for (auto s:st) count[s]++;
        }
                
        for (auto& iter:count) {
            if (iter.second>maxCount) {
                res=iter.first;
                maxCount=iter.second;
            } else if (iter.second==maxCount) {
                res=min(res, iter.first);
            }
        }
        
        auto pos=res.find(','), pos2=res.find(',', pos+1);
        return {res.substr(0, pos), res.substr(pos+1, pos2-pos-1), res.substr(pos2+1)};
    }
};

