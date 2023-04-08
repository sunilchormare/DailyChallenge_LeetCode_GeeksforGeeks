/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        if (!mp[node]) {
            mp[node] = new Node(node->val);
            for (auto n : node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(n));
        }
        
        return mp[node];
    }
};