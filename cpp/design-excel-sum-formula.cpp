631. Design Excel Sum Formula
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:

Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.


void Set(int row, char column, int val): Change the value at C(row, column) to be val.


int Get(int row, char column): Return the value at C(row, column).


int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.

numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).

If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.


Example 1:
Excel(3,"C"); 
// construct a 3*3 2D array with all zero.
//   A B C
// 1 0 0 0
// 2 0 0 0
// 3 0 0 0

Set(1, "A", 2);
// set C(1,"A") to be 2.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 0

Sum(3, "C", ["A1", "A1:B2"]);
// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4. 
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 4

Set(2, "B", 2);
// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
//   A B C
// 1 2 0 0
// 2 0 2 0
// 3 0 0 6
Note:
You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
The test cases are using double-quotes to represent a character.
Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.

Amazon
|
2

Microsoft
|
LeetCode

1. update on the fly
class Excel {
public:
    Excel(int H, char W) {
        this->height=H;
        this->width=W-'A'+1;
        data.resize(this->height, vector<int>(this->width));
    }
    
    void set(int r, char c, int v) {                        
        update(r, c, v);
        if (!depend[{r, c}].empty()) {
            for (auto& d:depend[{r, c}]) affect[d].erase({r, c});
            depend[{r, c}].clear();
        }
    }
    
    int get(int r, char c) {        
        return data[r-1][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {        
        if (!depend[{r, c}].empty()) {
            for (auto& d:depend[{r, c}]) affect[d].erase({r, c});
            depend[{r, c}].clear();
        }

        data[r-1][c-'A']=eval(r, c, strs);        
        return data[r-1][c-'A'];
    }

    void update(int r, char c, int v) {
        int diff=v-data[r-1][c-'A'];        
        queue<pair<int,char>> q;
        queue<int> diffq;
        q.push({r,c});
        diffq.push(diff);
        data[r-1][c-'A']=v;
        
        while (!q.empty()) {
            pair<int,char> f=q.front();
            int d=diffq.front();
            q.pop();
            diffq.pop();            
            
            for (auto& neighbor:affect[f]) {
                q.push(neighbor.first);
                diffq.push(d*neighbor.second);
                data[neighbor.first.first-1][neighbor.first.second-'A']+=d*neighbor.second;
            }
        }
    }
    
    int eval(int r, char c, vector<string>& strs) {
        int res=0;
        for (auto& s:strs) {
            if (s.find(':')==string::npos) {
                res+=evalCell(r, c, s);
            } else {
                res+=evalRange(r, c, s);
            }
        }        
        return res;
    }
    
    int evalCell(int r, char c, string& str) {
        char col=str[0];
        int row=0, i=1;
        while (i<str.size()) {
            row=row*10+str[i]-'0';
            i++;
        }
        affect[{row, col}][{r, c}]++;
        depend[{r, c}].insert({row, col});
        return get(row, col);
    }
    
    int evalRange(int r, char c, string& str) {
        int idx=str.find(':');
        string start=str.substr(0, idx);
        string end=str.substr(idx+1);
        int rowStart=0, rowEnd=0, colStart, colEnd, i;
        colStart=start[0];
        i=1;
        while (i<start.size()) {
            rowStart=rowStart*10+start[i]-'0';
            i++;
        }
        colEnd=end[0];
        i=1;
        while (i<end.size()) {
            rowEnd=rowEnd*10+end[i]-'0';
            i++;
        }
        int res=0;
        for (int i=rowStart; i<=rowEnd; i++) {
            for (int j=colStart; j<=colEnd; j++) {
                affect[{i, j}][{r, c}]++;
                depend[{r, c}].insert({i, j});
                res+=get(i, j);
            }
        }
        
        update(r, c, res);
        return res;
    }
    
    struct myhash
    {
        size_t operator()(const pair<int, int>& p) const
        {
            return (hash<int>{}(p.first)) ^ (hash<int>{}(p.second)<<1);
        }
    };

private:
    int height;
    int width;
    unordered_map<pair<int,char>, unordered_map<pair<int,char>, int, myhash>, myhash> affect;
    unordered_map<pair<int,char>, unordered_set<pair<int,char>, myhash>, myhash> depend;
    vector<vector<int>> data;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

2. eval on the fly
class Excel {
public:
    Excel(int H, char W) {
        this->height=H;
        this->width=W-'A'+1;
        data.resize(this->height, vector<int>(this->width));
    }
    
    void set(int r, char c, int v) {
        int idx=(r-1)*width+c-'A';
        data[r-1][c-'A']=v;
        mp.erase(idx);
    }
    
    int get(int r, char c) {
        int idx=(r-1)*width+c-'A';
        if (mp.find(idx)==mp.end()) return data[r-1][c-'A'];
        return eval(mp[idx]);
    }
    
    int sum(int r, char c, vector<string> strs) {
        int idx=(r-1)*width+c-'A';
        data[r-1][c-'A']=eval(strs);
        mp[idx]=strs;
        return data[r-1][c-'A'];
    }
    
    int eval(vector<string>& strs) {
        int res=0;
        for (auto& s:strs) {
            if (s.find(':')==string::npos) {
                res+=evalCell(s);
            } else {
                res+=evalRange(s);
            }
        }
        
        return res;
    }
    
    int evalCell(string& str) {
        char col=str[0];
        int row=0, i=1;
        while (i<str.size()) {
            row=row*10+str[i]-'0';
            i++;
        }
        return get(row, col);
    }
    
    int evalRange(string& str) {
        int idx=str.find(':');
        string start=str.substr(0, idx);
        string end=str.substr(idx+1);
        int rowStart=0, rowEnd=0, colStart, colEnd, i;
        colStart=start[0];
        i=1;
        while (i<start.size()) {
            rowStart=rowStart*10+start[i]-'0';
            i++;
        }
        colEnd=end[0];
        i=1;
        while (i<end.size()) {
            rowEnd=rowEnd*10+end[i]-'0';
            i++;
        }
        int res=0;
        for (int i=rowStart; i<=rowEnd; i++) {
            for (int j=colStart; j<=colEnd; j++) {
                res+=get(i, j);
            }
        }
        
        return res;
    }
private:
    int height;
    int width;
    unordered_map<int, vector<string>> mp;
    vector<vector<int>> data;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
