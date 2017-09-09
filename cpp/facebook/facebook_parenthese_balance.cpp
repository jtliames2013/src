input could include ":(" frown or ":)" smileys
check if the input is parenthese balance

class Solution {
public:
	bool balanceParenthsis(string message) {
		int open=0, close=0;
		for (int i=0; i<message.size(); i++) {
			if (message[i]=='(') {
				open++;
			} else if (message[i]==')') {
				close++;
				if (close>open) return false;
			} else if (message[i]==':') {
				if (i<message.size()) {
					if (message[i+1]=='(' || message[i+1]==')') {
						i++;
					}
				}
			}
		}
		return open==close;
	}
};



