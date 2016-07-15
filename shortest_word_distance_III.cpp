245. Shortest Word Distance III 
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list. 

NOTE: consider word1==word2 or not separately.

  class Solution {
  public:
      int shortestWordDistance(vector<string>& words, string word1, string word2) {
    	  int shortest=INT_MAX;
    	  if (word1!=word2) {
    		  int idx1=-1, idx2=-1;
    		  for(int i=0; i<words.size(); i++) {
    			  if (words[i]==word1) {
    				  idx1=i;
    				  if (idx2!=-1) {
    					  shortest=min(shortest, idx1-idx2);
    				  }
    			  } else if (words[i]==word2) {
    				  idx2=i;
    				  if (idx1!=-1) {
    					  shortest=min(shortest, idx2-idx1);
    				  }
    			  }
    		  }
    	  } else {
    		  int curr=-1;
    		  for (int i=0; i<words.size(); i++) {
    			  if (words[i]==word1) {
    				  if (curr==-1) {
    					  curr=i;
    					  continue;
    				  } else {
    					  shortest=min(shortest, i-curr);
    					  curr=i;
    				  }
    			  }
    		  }
    	  }

    	  return shortest;
      }
  };

2.

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
    	  int shortest=INT_MAX;
		  int curr=-1, idx1=-1, idx2=-1;
		  for(int i=0; i<words.size(); i++) {
			  if (words[i]==word1) {
				  idx1=i;
				  if (idx2!=-1) {
					  shortest=min(shortest, idx1-idx2);
				  }
				  if (curr!=-1) {
				      shortest=min(shortest, idx1-curr);
				  } 
				  curr=idx1;
			  } else if (words[i]==word2) {
				  idx2=i;
				  if (idx1!=-1) {
					  shortest=min(shortest, idx2-idx1);
				  }
			  }
		  }

    	  return shortest;
    }
};

