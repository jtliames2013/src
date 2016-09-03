This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list. 


  class WordDistance {
  public:
	  map<string, vector<int> > pos;

      WordDistance(vector<string>& words) {
    	  for (int i=0; i<words.size(); i++) {
    		  pos[words[i]].push_back(i);
    	  }
      }

      int shortest(string word1, string word2) {
    	  vector<int> v1=pos[word1];
    	  vector<int> v2=pos[word2];
    	  int dist=INT_MAX;
    	  int i=0, j=0;
    	  while (i<v1.size() && j<v2.size()) {
    		  if (v1[i]<v2[j]) {
    			  dist=min(dist, v2[j]-v1[i]);
    			  i++;
    		  } else {
    			  dist=min(dist, v1[i]-v2[j]);
    			  j++;
    		  }
    	  }

    	  return dist;
      }
  };


  // Your WordDistance object will be instantiated and called as such:
  // WordDistance wordDistance(words);
  // wordDistance.shortest("word1", "word2");
  // wordDistance.shortest("anotherWord1", "anotherWord2");

