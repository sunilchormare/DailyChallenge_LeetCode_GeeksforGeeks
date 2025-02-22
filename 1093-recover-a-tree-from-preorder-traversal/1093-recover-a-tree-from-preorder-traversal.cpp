class Solution {
public:
   TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stack.size() > level) stack.pop_back();
            if (!stack.empty())
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            stack.push_back(node);
        }
        return stack[0];
    }
};