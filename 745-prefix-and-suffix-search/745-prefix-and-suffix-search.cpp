//Time complexity : O(n*k)
//Space Complexity : O(TrieSize)

class WordFilter {

private:
    struct TrieNode { 
        vector<TrieNode*> children;
        int weight;
        TrieNode() {
            weight = 0;
            children.resize(27, NULL);
        }
    };
    
public:
    TrieNode* root;
        
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        int len = words.size();
        
       for(int weight=0; weight<words.size() ; weight++) {
           string word = '{' + words[weight];
           insert(root, word, weight); 
           
           for(int i=0; i<word.size(); i++) {
               insert(root, word.substr(i+1) + word, weight);
           }
       }
    }

    void insert(TrieNode* root, string word, int weight) {

        TrieNode* curr = root;

        for(auto& ch: word) {
            int n = ch - 'a';
            if(curr->children[n] == NULL)
                curr->children[n] = new TrieNode();

            curr = curr->children[n];
            curr->weight = weight;
        }
    }
    
    int f(string prefix, string suffix) {
        
        TrieNode* curr = root;
        for(char c: (suffix + '{' + prefix)) {
            if(curr->children[c-'a'] == NULL)
                return -1;
            
            curr = curr->children[c-'a'];
        }
        
        return curr->weight;
    }
};