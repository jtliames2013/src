Often, we want to encode raw IDs in our database by hiding them behind some
2-way decodeable hash. So, a URL which would have at one time been:
https://www.airbnb.com/rooms/848662
becomes
https://www.airbnb.com/rooms/kljJJ324hjkS_
We decode the ID kljJJ324hjkS_ to 848662 on our backend and serve the
relevant content. at some point, we start getting 404 errors from clients
requesting a certain URL of the form
https://www.airbnb.com/rooms/kljjj324hjks_
This can happen if certain clients, email services, or url shorteners "
sanitize" the url. Unfortunately, this change breaks decoding and the
resource cannot be found.
To assess how big of a deal this is, we may want to recover the IDs of the
targets that were 404ing.

Your task:
Given a method decode(testEncStr) which will return the decoded int id if
testEncStr is decodeable or will throw an exception or return null (
depending on the language) if not, implement a new method decodeFind(String
badEncStr) which takes a string and returns the decoded int id.

1. recursive
class Solution {
public:
	  int decode(string testEncStr) {
		  if (testEncStr=="kljJJ324hijkS_") return 848662;
		  else return -1;
	  }

	  int decodeFind(string& badEncStr, int start) {
		  if (start==badEncStr.size()) {			  
			  return decode(badEncStr);
		  }

		  if (isalpha(badEncStr[start])) {
			  badEncStr[start]=tolower(badEncStr[start]);
			  int res=decodeFind(badEncStr, start+1);
			  if (res!=-1) return res;
			  else {
				  badEncStr[start]=toupper(badEncStr[start]);
				  return decodeFind(badEncStr, start+1);
			  }
		  } else {
			  return decodeFind(badEncStr, start+1);
		  }
	  }
	  int decodeFind(string badEncStr) {
		  decodeFind(badEncStr, 0);
	  }
  };

int main()
{
	Solution s;
	string badEncStr = "kLjjj324hijks_";
	int res=s.decodeFind(badEncStr);
  	return 0;
}

2. iterative
class Solution {
public:
	  int decode(string testEncStr) {
		  if (testEncStr=="kljJJ324hijkS_") return 848662;
		  else return -1;
	  }

	  int decodeFind(string badEncStr) {
		  int n=badEncStr.size();
		  int i;
		  for (i=0; i<n; i++) {
			  if (isalpha(badEncStr[i])) {
				  badEncStr[i]=tolower(badEncStr[i]);
			  }
		  }
		  i=0;
		  int res;
		  while (i<n) {			
			  res=decode(badEncStr);
			  if (res!=-1) return res;

			  if (islower(badEncStr[i])) {
				  badEncStr[i]=toupper(badEncStr[i]);
			  } else {
				  while (i<n) {
					  if (islower(badEncStr[i])) break;
					  i++;
				  }
				  if (i==n) break;
				  badEncStr[i]=toupper(badEncStr[i]);
				  for (int j=0; j<i; j++) {
					  badEncStr[j]=tolower(badEncStr[j]);
				  }
				  i=0;
			  }
		  }
		  return -1;
	  }
  };

int main()
{
	Solution s;
	string badEncStr = "kLjjj324hijks_";
	int res=s.decodeFind(badEncStr);
  	return 0;
}


