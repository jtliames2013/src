http://blog.csdn.net/linhuanmars/article/details/23071455

这道题是LeetCode中AC率最低的题目，确实是比较难。一方面是因为对时间有比较严格的要求（容易超时），另一方面是它有很多细节需要实现。思路上和Word Ladder是比较类似的，但是因为是要求出所有路径，仅仅保存路径长度是不够的，而且这里还有更多的问题，那就是为了得到所有路径，不是每个结点访问一次就可以标记为visited了，因为有些访问过的结点也会是别的路径上的结点，所以访问的集合要进行回溯（也就是标记回未访问）。所以时间上不再是一次广度优先搜索的复杂度了，取决于结果路径的数量。同样空间上也是相当高的复杂度，因为我们要保存过程中满足的中间路径到某个数据结构中，以便最后可以获取路径，这里我们维护一个HashMap，把一个结点前驱结点都进行保存。
在LeetCode中用Java实现上述算法非常容易超时。为了提高算法效率，需要注意一下两点：
1）在替换String的某一位的字符时，先转换成char数组再操作；
2）如果按照正常的方法从start找end，然后根据这个来构造路径，代价会比较高，因为保存前驱结点容易，而保存后驱结点则比较困难。所以我们在广度优先搜索时反过来先从end找start，最后再根据生成的前驱结点映射从start往end构造路径，这样算法效率会有明显提高。

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        queue<vector<string>> q;
        unordered_set<string> visited;
        wordList.insert(endWord);
        q.push({beginWord});
        int level=1;
        int minlevel=INT_MAX;
        
        while (!q.empty()) {
            vector<string> path=q.front();
            q.pop();
            if (path.size()>level) {
                for (auto w:visited) wordList.erase(w);
                visited.clear();
                if (path.size()>minlevel) break;
                else level=path.size();
            }
            
            string last=path.back();
            for (int i=0; i<last.size(); i++) {
                string next=last;
                for (char c='a'; c<='z'; c++) {
                    next[i]=c;
                    if (wordList.find(next)!=wordList.end()) {
                        vector<string> newpath=path;
                        newpath.push_back(next);
                        visited.insert(next);
                        if (next==endWord) {
                            minlevel=level;
                            res.push_back(newpath);
                        } else {
                            q.push(newpath);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

