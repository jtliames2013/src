1410. HTML Entity Parser
Medium

7

42

Add to List

Share
HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

The special characters and their entities for HTML are:

Quotation Mark: the entity is &quot; and symbol character is ".
Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.

 

Example 1:

Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &
Example 2:

Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""
Example 3:

Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"
Example 4:

Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"
Example 5:

Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"
 

Constraints:

1 <= text.length <= 10^5
The string may contain any possible characters out of all the 256 ASCII characters.

class Solution {
public:
    string entityParser(string text) {
        string res;
        int n=text.size();
        for (int i=0; i<n; ) {
            int j=0;
            for (; j<data.size(); ++j) {
                string str=text.substr(i, min((int)data[j].first.size(), n-i));
                if (str==data[j].first) {
                    res+=data[j].second;
                    i+=data[j].first.size();
                    break;
                }
            }
            if (j==data.size()) res.push_back(text[i++]);
        }

        return res;
    }
private:
    vector<pair<string, string>> data={
        {"&lt;", "<"},
        {"&gt;", ">"},
        {"&amp;", "&"},
        {"&apos;", "'"},
        {"&quot;", "\""},
        {"&frasl;", "/"}
    };
};

