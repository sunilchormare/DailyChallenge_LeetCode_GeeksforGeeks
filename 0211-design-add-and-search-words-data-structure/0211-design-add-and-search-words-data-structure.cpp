class WordDictionary {
    WordDictionary *child[26];
    bool isLastChar;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        for (auto i = 0; i < 26; i++) {
            this->child[i] = NULL;
        }
        isLastChar = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *curr = this;
        for(auto &c: word) {
            if(!curr->child[c - 'a'])
                curr->child[c - 'a'] = new WordDictionary();
            curr = curr->child[c - 'a'];
        }
        curr->isLastChar = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *curr = this;
        for(auto i = 0; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(auto &ch: curr->child) {
                    if(ch && ch->search(word.substr(i+1)))
                        return true;
                }
                return false;
            } else if(!curr->child[c - 'a'])
                return false;
            else 
                curr = curr->child[c - 'a'];
        }
        return curr->isLastChar;
    }
};