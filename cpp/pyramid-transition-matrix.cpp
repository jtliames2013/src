757. Pyramid Transition Matrix
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
Example 1:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
Note:
bottom will be a string with length in range [2, 100].
allowed will have length in range [0, 350].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

Approach #1: Block to State Transition [Accepted]
Intuition and Algorithm

We model the states that blocks could be in. We can do this using binary: a number like 0b0001011 would correspond to the state of the block being either 'A', 'B', or 'D'.

After, we will build a map T[x][y] = state where x and y are integers 0 <= x, y < 7 representing single blocks. This represents our transition: if we have a left child x and a right child y, what states could we be in?

When applying this transition to two child states X and Y, for every set bit x in X and y in Y, we add T[x][y] to the possible states.

Approach #2: State to State Transition [Accepted]
Intuition and Algorithm

As in Approach #1, we model the states that blocks can be in.

For our transition T, instead of the arguments being single blocks, we will make the arguments states directly. This requires precomputing all possible state transitions.

At the end, applying these transitions is straightforward.

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<int>> T((1 << 7), vector<int>((1 << 7)));
        for (auto& triple:allowed) {
            int u = (1 << (triple[0] - 'A'));
            int v = (1 << (triple[1] - 'A'));
            int w = (1 << (triple[2] - 'A'));
            for (int b1 = 0; b1 < (1 << 7); b1++) {
                if ((u & b1) > 0) {
                    for (int b2 = 0; b2 < (1 << 7); b2++) {
                        if ((v & b2) > 0) T[b1][b2] |= w;
                    }
                }
            }
        }

        vector<int> state(bottom.size());
        int t=0;
        for (auto c:bottom) {
            state[t++] = (1 << (c-'A'));            
        }        
        while (t>1) {
            for (int i=0; i<t-1; i++) state[i]=T[state[i]][state[i+1]];
            t--;
        }
        return state[0]>0;        
    }
};


