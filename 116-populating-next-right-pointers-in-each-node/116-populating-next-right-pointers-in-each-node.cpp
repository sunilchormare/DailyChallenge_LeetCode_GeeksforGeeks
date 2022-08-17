class Solution {
public:
    Node* connect(Node* root) {
//         if (root)
//            {
//       if (root->left)
//       {
//         root->left->next = root->right;
//         if (root->next)
//           root->right->next = root->next->left;
        
//           connect(root->left);
//         connect(root->right);
//       }
//     }
//     return root;
        
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                if(i!=n-1)x->next=q.front();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        return root;
    }
};