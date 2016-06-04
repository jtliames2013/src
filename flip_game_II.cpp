 You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity. 

  class Solution {
  public:
	  bool canWinGame(string& s) {
		  int size=s.size();
		  for (int i=0; i<size-1; i++) {
			  if (s[i]=='+' && s[i+1]=='+') {
				  s[i]='-'; s[i+1]='-';
				  bool win=canWinGame(s);
				  s[i]='+'; s[i+1]='+';
				  if (win==false) return true;
			  }
		  }

		  return false;
	  }

      bool canWin(string s) {
    	  return canWinGame(s);
      }
  };

