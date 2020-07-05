// 一个N*N的grid, 里面battleship是一个横着或者竖着的一条线（三个格子），
// 要找到battleship的坐标 可以每次隔3个格子 按行扫、按列扫，输出坐标需要输出battleship的三个格子的各自坐标...

// 实在一个square里面找battership的位置，battership会连续占据三个的位置，或是横着或是竖着。
// 里面会有一个给定函数来判断给定位置是不是有船，最后要求输出battership占据三个位置的坐标。
// Battleship game: write a function that finds a ship and return its coordinates.

MAX_ID = 100
NUM_ROW = 10
NUM_COL = 10
SIZE = 3

class App:
    def __init__(self):
        self.id=random.randrange(0, MAX_ID)

    def run(self, args):
        board=[['O' for j in range(NUM_COL)] for i in range(NUM_ROW)]
        board[1][4]='X'
        board[2][4]='X'
        board[3][4]='X'
        board[5][5]='X'
        board[5][6]='X'
        board[5][7]='X'
        for i in range(len(board)):
            print(board[i])
        res=self.findBattleShip(board)
        print(res)

    def findBattleShip(self, board):
        def check(row, col, delta):
            count=1
            nr, nc=row, col
            for _ in range(SIZE-1):
                nr+=delta[0]
                nc+=delta[1]
                if nr<0 or nr>=m or nc<0 or nc>=n or board[nr][nc]!='X': break
                count+=1
                if count==SIZE: return True
            return False

        res=[]
        m, n=len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j]=='X':
                    if (i==0 or board[i-1][j]!='X') and (j==0 or board[i][j-1]!='X'):
                        delta=[0, 1]
                        if check(i, j, delta):
                            res.append([[i, j], [i, j+1], [i, j+2]])
                        delta=[1, 0]
                        if check(i, j, delta):
                            res.append([[i, j], [i+1, j], [i+2, j]])

        return res

def parse():
    parser = argparse.ArgumentParser()

    args = parser.parse_args()
    return args

def run():
    args=parse()
    App().run(args)

if __name__ == '__main__':
    run()


