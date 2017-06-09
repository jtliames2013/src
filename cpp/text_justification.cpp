68. Text Justification 
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
Hide Company Tags LinkedIn Airbnb
Hide Tags String

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int width;
        for (int i=0, j=0; i<words.size(); ) {
            width=0;
            while (j<words.size()) {
                if (width+words[j].size()+j-i>maxWidth) break;
                width+=words[j].size();
                j++;
            }
            
            string line;
            int numWords=j-i, totalSpace=maxWidth-width;
            int div=numWords==1?totalSpace:totalSpace/(numWords-1);
            int mod=numWords==1?0:totalSpace%(numWords-1);
            for (int k=i; k<j; k++) {
                line+=words[k];
                if (totalSpace>0) {
                    int space;
                    if (j==words.size()) {
                        // last line
                        space=k==j-1?totalSpace:1;
                    } else {
                        space=div;
                        if (k-i<mod) space+=1;
                    }
                    
                    line.append(space, ' ');
                    totalSpace-=space;
                }
            }
            
            res.push_back(line);
            i=j;
        }
        
        return res;
    }
};

