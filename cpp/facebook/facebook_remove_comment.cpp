remove comments in code, 要考虑 code 里有 //

The idea is to maintain two flag variables, one to indicate that a single line comment is started, another to indicate that a multiline comment is started. When a flag is set, we look for the end of comment and ignore all characters between start and end.

class Solution {
public:
	string removeComment(string code) {
		string res;
		bool singleline=false, multiline=false;
		for (int i=0; i<code.size(); i++) {
			if (singleline && code[i]=='\n') {
				singleline=false;
			} else if (multiline && code[i]=='*' && code[i+1]=='/') {
				multiline=false;
				i++;
			} else if (singleline || multiline) {
				continue;
			} else if (code[i]=='/' && code[i+1]=='/') {
				singleline=true;
				i++;
			} else if (code[i]=='/' && code[i+1]=='*') {
				multiline=true;
				i++;
			} else {
				res+=code[i];
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	string prgm = "   /* Test program */ \n"
	                  "   int main()  \n"
	                  "   {           \n"
	                  "      // variable declaration \n"
	                  "      int a, b, c;    \n"
	                  "      /* This is a test  \n"
	                  "          multiline     \n"
	                  "          comment for   \n"
	                  "          testing */      \n"
	                  "      a = b + c;       \n"
	                  "   }           \n";

	cout << s.removeComment(prgm) << endl;
	return 0;
}

