struct TrieNode {
    TrieNode* child[26] = {};
    int sum = 0; // Store the sum of values of all strings go through this node.
};

class MapSum { // 0 ms, faster than 100.00%
public:
    unordered_map<string, int> map;
    TrieNode trieRoot;
    
    void insert(const string& key, int val) {
        int diff = val - map[key];
        TrieNode* curr = &trieRoot;
        for (char c : key) {
            c -= 'a';
            if (curr->child[c] == nullptr) curr->child[c] = new TrieNode();
            curr = curr->child[c];
            curr->sum += diff;
        }
        map[key] = val;
    }
    int sum(const string& prefix) {
        TrieNode* curr = &trieRoot;
        for (char c : prefix) {
            c -= 'a';
            if (curr->child[c] == nullptr) return 0;
            curr = curr->child[c];
        }
        return curr->sum;
    }
};