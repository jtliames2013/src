public class WordDictionary {

    class TrieNode {
        boolean isWord;
        Map<Character, TrieNode> children;
    }
    
    TrieNode root;
    
    WordDictionary() {
        root=new TrieNode();        
    }
    
    // Adds a word into the data structure.
    public void addWord(String word) {
        int i;
        TrieNode node=root;
        char[] wordArray=word.toCharArray();
        for (i=0; i<wordArray.length; i++) {
            if (node.children==null || !node.children.containsKey(wordArray[i])) break;
            node=node.children.get(wordArray[i]);
        }
        
        for (; i<wordArray.length; i++) {
            TrieNode curr=new TrieNode();
            if (node.children==null) {
                node.children=new TreeMap<Character, TrieNode>();
            }
            node.children.put(wordArray[i], curr);
            node=curr;
        }
        node.isWord=true;
    }

    boolean search(char[] word, int start, TrieNode node) {
        if (start==word.length) {
            return node.isWord;
        }    
        
        if (word[start]!='.') {
            if (node.children!=null && node.children.containsKey(word[start])) {
                node=node.children.get(word[start]);
                return search(word, start+1, node);
            } else {
                return false;
            }
        } else {
            if (node.children!=null) {
                for (Map.Entry<Character, TrieNode> entry:node.children.entrySet()) {
                    if (search(word, start+1, entry.getValue())) return true;
                }
            }
            return false;
        }
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        return search(word.toCharArray(), 0, root);
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
