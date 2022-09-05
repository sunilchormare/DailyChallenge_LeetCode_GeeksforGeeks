/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> ret ;
        
        if (root == NULL) return ret;
        
        queue<Node*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            vector<int> curLevel;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                Node* curr = q.front(); q.pop();
                curLevel.push_back(curr->val);
                for (Node* c : curr->children)
                     q.push(c);
            }
            ret.push_back(curLevel);
        }
        
        return ret;
    }
};