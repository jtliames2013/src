class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList=set(wordList)
        steps=1
        q=collections.deque([beginWord])
        while q:
            size=len(q)
            for i in range(size):
                f=q.popleft()
                for j in range(len(f)):
                    for c in ascii_lowercase:
                        if c==f[j]: continue
                        w=f[:j]+c+f[j+1:]
                        if w in wordList:
                            if w==endWord: return steps+1
                            q.append(w)
                            wordList.remove(w)
            steps+=1
        return 0

