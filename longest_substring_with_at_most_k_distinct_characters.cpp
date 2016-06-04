// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

//这题的线性解法是维护一个sliding window，里面的子字符串只含最多两个不同字符。当要添加一个新字符时，需要完全去掉之前的某一个字符的所有出现。这里有两个问题需要考虑：
//
//1）在已有的两个字符中，如何选择该去掉其所有出现的字符？
//
//2）在选定该去掉的字符后，如何改调整窗口？
//
//对于问题1，窗口起始处的字符是一定会被去掉的，但是否总是应该选择这个字符然后去掉其所有出现么？以“abac”为例，可以发现当扫描到c时，a是一定会被去掉的，但是如果去掉所有出现过的a，那么最后只剩下"c"了。这时应该是去掉所有出现的b，顺便去掉了最开始的a，从而得到"ac"。由此观之，选择标准应该是字符的最后出现的位置，最后出现的位置越左（早），则其出现被全部删除后所减小的长度越少。因此，应该删光最后出现位置在最左的字符。
//
//对于问题2，由于题目规定了窗口里最多只会有2种字符，其实怎么删都可以：慢点的可以从左到右逐个删除，快点的可以直接让新窗口以所选字符的最后出现位置的下一个字符打头。
//
//以下代码用了一个Map结构来表示sliding window，key为字符，value为对应的最后出现位置。其实也可以完全避免使用Map，因为里面的entry最多只有两个，比较浪费空间。这里是考虑到了后来的扩展以及代码的维护。
//
//这里为了获得Map的最后位置最早出现的字符，遍历了所有的entry。这其实是非常低效的，但考虑到Map里实际只有2个元素，所以遍历的开销也很小，可以忽略不计。

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> pos;
        int longest=0;
        // Use start to record the start of substring
        int start=0;
        for (int i=0; i<s.size(); i++) {
            // When map is full and the new char is not in map
            // find a char to replace
            if (pos.size()==k && pos.find(s[i])==pos.end()) {
                char leftMost;
                int leftMostIdx=INT_MAX;
                for (auto p:pos) {
                    if (p.second<leftMostIdx) {
                        leftMost=p.first;
                        leftMostIdx=p.second;
                    }
                }
                pos.erase(leftMost);
                start=leftMostIdx+1;
            }

            // Always update the position of last appearance
            pos[s[i]]=i;
            longest=max(longest, i-start+1);
        }

        return longest;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
