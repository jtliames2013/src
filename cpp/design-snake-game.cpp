353. Design Snake Game 
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Amazon
|
4

Google
|
3

Uber
|
2

Facebook
|
2

Salesforce
|
2

Zillow
|
2

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width=width;
        this->height=height;
        this->food=food;
        snake.push_back({0, 0});
        st.insert({0, 0});
        idx=0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int> delta(2), next(2);
        if (direction=="U") delta={-1, 0};
        else if (direction=="L") delta={0, -1};
        else if (direction=="R") delta={0, 1};
        else delta={1, 0};
        
        next[0]=snake.front()[0]+delta[0];
        next[1]=snake.front()[1]+delta[1];
        if (next[0]<0 || next[0]>=height || next[1]<0 || next[1]>=width) return -1;
        if (idx<food.size() && next==food[idx]) {
            idx++;
        } else {
            st.erase(snake.back());
            snake.pop_back();
            if (st.find(next)!=st.end()) return -1;
        }
        st.insert(next);
        snake.push_front(next);
        
        return idx;
    }
private:
    int width;
    int height;
    vector<vector<int>> food;
    deque<vector<int>> snake;
    set<vector<int>> st;
    int idx;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */


