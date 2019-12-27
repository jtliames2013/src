251. Flatten 2D Vector 
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Hint:

How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Airbnb
|
6

1. Use index
class Vector2D {
public:
    void tryAdvance() {
        while (row<vec2d.size()) {
            if (col<vec2d[row].size()) break;
            row++;
            col=0;
        }
    }
    
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d=vec2d;
        row=col=0;
        tryAdvance();
    }

    int next() {
        if (!hasNext()) return -1;
        int res=vec2d[row][col];
        col++;
        tryAdvance();
        return res;
    }

    bool hasNext() {
        return row<vec2d.size();
    }
private:
    vector<vector<int>> vec2d;
    int row;
    int col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

2. Use iterator
class Vector2D {
public:
    void tryAdvance() {
        while (rowIter!=vec2d.end()) {
            if (colIter!=rowIter->end()) break;
            rowIter++;
            if (rowIter!=vec2d.end()) colIter=rowIter->begin();
        }
    }
    
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d=vec2d;
        rowIter=this->vec2d.begin();
        if (rowIter!=this->vec2d.end()) colIter=rowIter->begin();
        tryAdvance();
    }

    int next() {
        if (!hasNext()) return -1;
        int res=*colIter;
        colIter++;
        tryAdvance();
        return res;
    }

    bool hasNext() {
        return rowIter!=vec2d.end();
    }
private:
    vector<vector<int>> vec2d;
    vector<vector<int>>::iterator rowIter;
    vector<int>::iterator colIter;
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

