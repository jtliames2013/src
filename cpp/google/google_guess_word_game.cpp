given a dict of word，guess word game

基本思路就是按照系统的反馈情况去给你的字典里面删词，然后各种优化其实可以自由发挥，言之成理，并且能够顺利实现即可

I've been asked the same question. The guess game one. It is something related to making the guess that will keep decreasing the size of the result set( the set that contains all the possible string). You can think of a graph that contains strings as nodes. The edges are weighted. The weights are the common characters for two strings. Make the guess that wil result the smallest expected size of the result set after each guess.

其实可以建立一个 hashset 然后把字典里 makecount(word) 与原guess 里面 char相同数量的 单词找出来, 然后再从这个set 里面再找一个字出来, 再makecount, 在一步步进行loop 一直到只剩下一个 单词为止
