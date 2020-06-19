class TrieNode:
    def __init__(self):
        self.children=collections.defaultdict(TrieNode)
        self.isWord=False
        
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root=TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node=self.root
        for w in word:
            node=node.children[w]
        node.isWord=True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        def dfs(word, start, node):
            if start==len(word): return node.isWord
            if word[start]=='.':
                for v in node.children.values():
                    if dfs(word, start+1, v): return True
                return False
            else:
                if word[start] not in node.children: return False
                return dfs(word, start+1, node.children[word[start]])
            
        return dfs(word, 0, self.root)        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

