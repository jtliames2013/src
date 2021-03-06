1311. Get Watched Videos by Your Friends
Medium

50

76

Add to List

Share
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

 

Example 1:



Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"] 
Explanation: 
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
Person with id = 1 -> watchedVideos = ["C"] 
Person with id = 2 -> watchedVideos = ["B","C"] 
The frequencies of watchedVideos by your friends are: 
B -> 1 
C -> 2
Example 2:



Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
Output: ["D"]
Explanation: 
You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).
 

Constraints:

n == watchedVideos.length == friends.length
2 <= n <= 100
1 <= watchedVideos[i].length <= 100
1 <= watchedVideos[i][j].length <= 8
0 <= friends[i].length < n
0 <= friends[i][j] < n
0 <= id < n
1 <= level < n
if friends[i] contains j, then friends[j] contains i

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> res;
        unordered_map<string, int> mp;
        vector<pair<string, int>> freq;
        queue<int> q;
        unordered_set<int> visited;
        q.push(id);
        visited.insert(id);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                if (level==0) {
                    for (auto& v:watchedVideos[f]) mp[v]++;
                }
                
                if (level>0) {
                    for (auto& neighbor:friends[f]) {
                        if (visited.find(neighbor)==visited.end()) {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
            level--;
        }
        
        for (auto& iter:mp) freq.push_back({iter.first, iter.second});
        sort(freq.begin(), freq.end(), [](pair<string, int>& a, pair<string, int>& b){ return a.second<b.second || (a.second==b.second && a.first<b.first); });
        for (auto& p:freq) res.push_back(p.first);
        return res;
    }
};

