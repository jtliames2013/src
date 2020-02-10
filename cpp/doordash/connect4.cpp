https://en.wikipedia.org/wiki/Connect_Four

class Connect4 {
public:
    Connect4() {
        rowIndex.resize(numCols, numRows-1);
        mat.resize(numRows, vector<int>(numCols));
    }

    int move(int col, int player) {
        if (col<0 || col>=numCols || rowIndex[col]<0) return -1;
        int row=rowIndex[col];
        mat[row][col]=player;
        rowIndex[col]--;
        print();

        if (check(row, col, player)) return player;                
        return 0;
    }

    bool check(int row, int col, int player) {        
        vector<vector<int>> delta;
        // check row
        delta={{0, -1}, {0, 1}};
        if (checkOne(row, col, player, delta)) return true;

        // check col
        delta={{-1, 0}, {1, 0}};
        if (checkOne(row, col, player, delta)) return true;

        // check diag
        delta={{-1, -1}, {1, 1}};
        if (checkOne(row, col, player, delta)) return true;

        // check antidiag
        delta={{-1, 1}, {1, -1}};
        if (checkOne(row, col, player, delta)) return true;

        return false;
    }

    bool checkOne(int row, int col, int player, vector<vector<int>>& delta) {
        int count=1;
        for (int k=0; k<2; ++k) {
            int nr=row, nc=col;
            for (int i=0; i<num; ++i) {
                nr+=delta[k][0];
                nc+=delta[k][1];
                if (nr<0 || nr>=numRows || nc<0 || nc>=numCols) break;
                if (mat[nr][nc]!=player) break;
                count++;
                if (count==num) return true;
            }            
        }
        return false;
    }

    int findBestCol(int player) {
        // find if there is col that current player can win
        // find if there is col that next player can win
        // choose the center of the board

        // naive, find the first valid col
        for (int i=0; i<numCols; ++i) {
            if (rowIndex[i]>=0) return i;
        }
        return 0;
    }

    void print() {
        for (int i=0; i<numCols; ++i) {
            if (i>0) cout << ", ";
            cout << rowIndex[i];
        }
        cout << endl << endl;

        for (int i=0; i<numRows; ++i) {
            for (int j=0; j<numCols; ++j) {
                if (j>0) cout << ", ";
                cout << mat[i][j];
            }
            cout << endl;        
        }
        cout << endl;
    }
private:
    const int numRows=6;
    const int numCols=7;
    const int num=4;
    vector<int> rowIndex;
    vector<vector<int>> mat;
};

class IRobot {
public:
	virtual ~IRobot() {}
	virtual int move(Connect4& c, int player) = 0;
};

class ManualRobot: public IRobot {
public:
    int move(Connect4& c, int player) {
        int col=getInput(player);
        return c.move(col, player);
    }

private:
    int getInput(int player) {
        int col;
        cout << "Please input the column for player " << player << ": " << endl;
        cin >> col;
        return col;
    }
};

class SmartRobot: public IRobot {
public:
    int move(Connect4& c, int player) {
        int col=findBestCol(c, player);
        return c.move(col, player);
    }
private:
    int findBestCol(Connect4& c, int player) {
        return c.findBestCol(player);
    }
};

int main(int argc, char** argv) {
    Connect4 c;
    int player=1;
    ManualRobot mr;
    SmartRobot sr;
    while (1) {
        int res=sr.move(c, player);
        if (res>0) {
            cout << "Player "<< res << " wins!" << endl;
            break;
        } else if (res<0) {
            cout << "Invalid input!" << endl;
            break;
        }

        player=player==1?2:1;
    }

    return 0;
}

