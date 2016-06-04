// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Vector2D {
    void advance() {
        while (rowIter!=endIter) {
            if (colIter!=rowIter->end()) break;
            rowIter++;
            colIter=rowIter->begin();
        }
    }

public:
    Vector2D(vector<vector<int>>& vec2d) {
        rowIter=vec2d.begin();
        endIter=vec2d.end();
        if (rowIter!=endIter) colIter=rowIter->begin();
        advance();
    }

    int next() {
        int n=*colIter;
        colIter++;
        advance();

        return n;
    }

    bool hasNext() {
        return rowIter!=endIter;
    }
private:
    vector<vector<int>>::iterator rowIter;
    vector<vector<int>>::iterator endIter;
    vector<int>::iterator colIter;
};

class Vector2D {
    void advance() {
        col++;
        while (row<v.size()) {
            if (col<v[row].size()) break;
            row++;
            col=0;
        }
    }

public:
    Vector2D(vector<vector<int>>& vec2d) {
        v=vec2d;
        row=0;
        col=-1;
        advance();
    }

    int next() {
        int n=v[row][col];
        advance();

        return n;
    }

    bool hasNext() {
        if (row<v.size()) return true;
        else return false;
    }
private:
    vector<vector<int>> v;
    int row;
    int col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

