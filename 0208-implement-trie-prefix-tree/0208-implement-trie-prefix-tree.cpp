class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch:word){
            ch-='a';
            if(!node->child[ch]) {node->child[ch] = new Trie();}
            node = node->child[ch];
        }
        node->isword = true;
        
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch:word){
            ch-='a';
            if(!node->child[ch]) return false;
            node = node->child[ch];
        }
        return node->isword;
    }
    
    bool startsWith(string prefix) {
         Trie* node = this;
        for(char ch:prefix){
            ch-='a';
            if(!node->child[ch]) return false;
            node = node->child[ch];
        }
        return true;
    }
    private:
    Trie* child[26] = {};
    bool isword = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */