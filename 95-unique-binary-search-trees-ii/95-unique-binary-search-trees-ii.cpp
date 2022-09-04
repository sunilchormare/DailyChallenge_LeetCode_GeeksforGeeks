class Solution {
public:
    vector<TreeNode*> rec( int start , int end  ){
      if( start > end ){
        return {NULL};
      }
      vector<TreeNode*> leftlist, rightlist,result;
      for( int i = start ; i <= end ; i++ ){
        leftlist = rec( start , i-1 );
        rightlist = rec( i+1,end);
        for( auto l : leftlist ){
          for( auto r : rightlist ){
            TreeNode* node = new TreeNode(i);
            node->left = l;
            node->right = r;
            result.push_back(node);
          }
        }
      }
      
      return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec( 1, n );
    }
};