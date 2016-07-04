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

Hide Company Tags Google
Hide Tags Design Queue

  class SnakeGame {
  public:
      /** Initialize your data structure here.
          @param width - screen width
          @param height - screen height
          @param food - A list of food positions
          E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
      SnakeGame(int width, int height, vector<pair<int, int>> food) {
    	  row=height;
    	  col=width;
    	  score=0;
    	  snake.push_back({0,0});
    	  for (auto f:food) {
    		  this->food.push_back(f);
    	  }
      }

      pair<int, int> getDelta(string dir) {
    	  if (dir=="U") return {-1,0};
    	  else if (dir=="L") return {0,-1};
    	  else if (dir=="R") return {0,1};
    	  else if (dir=="D") return {1,0};
    	  else return {0,0};
      }

      /** Moves the snake.
          @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
          @return The game's score after the move. Return -1 if game over.
          Game over when snake crosses the screen boundary or bites its body. */
      int move(string direction) {
    	  pair<int,int> f=snake.front();
    	  pair<int,int> delta=getDelta(direction);
    	  pair<int,int> next;
    	  next.first=f.first+delta.first;
    	  next.second=f.second+delta.second;
    	  if (next.first<0||next.first>=row||next.second<0||next.second>=col) return -1;
    	  for (int i=0; i<snake.size()-1; i++) {
    		  // head can run into tail
			  if (next==snake[i]) return -1;
		  }

    	  snake.push_front(next);
    	  if (!food.empty() && next==food.front()) {
    		  // eat food
    		  food.pop_front();
    		  score++;
    	  } else {
    		  snake.pop_back();
    	  }

    	  return score;
      }
  private:
      deque<pair<int,int> > snake;
      deque<pair<int,int> > food;
      int row;
      int col;
      int score;
  };

  /**
   * Your SnakeGame object will be instantiated and called as such:
   * SnakeGame obj = new SnakeGame(width, height, food);
   * int param_1 = obj.move(direction);
   */

