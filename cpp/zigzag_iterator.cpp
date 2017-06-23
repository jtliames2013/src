281. Zigzag Iterator 
 Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]

It should return [1,4,8,2,5,9,3,6,7]. 

class ZigzagIterator {
public:
    void tryAdvance() {
        int curr=row;
        do {
            if (col[row]<vec2d[row].size()) break;
            row=(row+1)%vec2d.size();
        } while (curr!=row);
    }
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vec2d.push_back(v1);
        vec2d.push_back(v2);
        row=0;
        col.resize(2,0);
        tryAdvance();
    }

    int next() {
        if (!hasNext()) return -1;
        int res=vec2d[row][col[row]];
        col[row]++;
        row=(row+1)%vec2d.size();
        tryAdvance();
        return res;
    }

    bool hasNext() {
        return col[row]<vec2d[row].size();
    }
private:
    vector<vector<int>> vec2d;
    int row;
    vector<int> col;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

2. Implement remove() that remove the previous next
class ZigzagIterator {
public:
    void tryAdvance() {
        int currRow=row;
        while (1) {
            if (idx[row]<lists[row].size()) break;
            row=(row+1)%size;
            if (row==currRow) break;
        }
    }
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        lists.push_back(v1);
        lists.push_back(v2);
        idx.resize(2, 0);
        row=0;
        size=2;
        tryAdvance();
    }

    int next() {
        if (hasNext()) {
            int res=lists[row][idx[row]];
            toRemove.push_back({row, idx[row]});
            idx[row]++;
            row=(row+1)%size;
            tryAdvance();
            return res;
        } else {
            return -1;
        }
    }

    bool hasNext() {
        if (idx[row]<lists[row].size()) return true;
        else return false;
    }
    
    void remove() {
        if (toRemove.size()==0) return;
        int i=toRemove.back().first;
        int j=toRemove.back().second;
        toRemove.pop_back();
        lists[i].erase(lists[i].begin()+j);
    }
private:
    vector<vector<int>> lists;
    vector<int> idx;
    vector<pair<int,int>> toRemove;
    int row;
    int size;
};

