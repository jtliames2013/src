/*
John,Smith,john.smith@gmail.com,Los Angeles,1
Jane,Roberts,janer@msn.com,"San Francisco, CA",0
"Alexandra ""Alex""",Menendez,alex.menendez@gmail.com,Miami,1
"""Alexandra Alex"""
John|Smith|john.smith@gmail.com|Los Angeles|1
Jane|Roberts|janer@msn.com|San Francisco, CA|0
Alexandra "Alex"|Menendez|alex.menendez@gmail.com|Miami|1
"Alexandra Alex"
*/

Understand the problem:
For this problem, there are several cases need to consider:
1. For comma, transform to |
2. If comma is inside a quote, don't treat the comma as separated. Remove the comma and print the entire token. e.g. "San Francisco, CA" => San Francisco, CA
3. If there are double quotes, remove one. e.g. "Alexandra ""Alex""" => Alexandra "Alex". 
Note that """Alexandra Alex""" becomes "Alexandra Alex" because we first remove the outer-most quote, and then remove one quote of the double quote.

class Solution {
public:
	  vector<string> parseCSV(string s) {
		  vector<string> res;
		  bool inQuote=false;
		  string part;
		  for (int i=0; i<s.size(); i++) {
			  if (!inQuote) {
				  if (s[i]=='"') {
					  inQuote=true;
				  } else if (s[i]==',') {
					  res.push_back(part);
					  part.clear();
				  } else {
					  part.push_back(s[i]);
				  }
			  } else {
				  if (s[i]=='"') {
					  if (i==s.size()-1) {
						  res.push_back(part);
						  part.clear();
					  } else if (s[i+1]=='"') {
						  part.push_back('"');
						  // pass double quote
						  i++;
					  } else {
						  // next must be comma
						  res.push_back(part);
						  part.clear();
						  // pass quote and comma
						  inQuote=false;
						  i++;
					  }
				  } else {
					  part.push_back(s[i]);
				  }
			  }
		  }

		  // the last part without comma ending
		  if (part.size()>0) res.push_back(part);

		  return res;
	  }
  };

void printVector(vector<string> v) {
	for (int i=0; i<v.size(); i++) {
		if (i>0) cout << "|";
		cout << v[i];
	}
	cout << endl;
}

int main()
{
	Solution s;
	string str1="John,Smith,john.smith@gmail.com,Los Angeles,1";
	printVector(s.parseCSV(str1));
	string str2="Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0";
	printVector(s.parseCSV(str2));
	string str3="\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1";
	printVector(s.parseCSV(str3));
	string str4="\"\"\"Alexandra Alex\"\"\"";
	printVector(s.parseCSV(str4));

  	return 0;
}

