class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
//        if(depth==1)
//        {
//            TreeNode ans=new TreeNode(val);
//            ans.left=root;
//            return ans;
//        }
//         Queue<TreeNode> q=new LinkedList<>();
//         q.offer(root);
//         while(depth-->2)
//         {
//             Queue<TreeNode> temp=new LinkedList<>();
//             while(!q.isEmpty())
//             {
//                 TreeNode top=q.poll();
//                 if(top.left!=null) temp.add(top.left);
//                 if(top.right!=null) temp.add(top.right);
                
//             }
//             q=temp;
//         }
//         while(!q.isEmpty())
//         {TreeNode top=q.poll();
//          TreeNode temp=top.left;
//          top.left=new TreeNode(val);
//          top.left.left=temp;
//          temp=top.right;
//          top.right=new TreeNode(val);
//          top.right.right=temp;
//         }
//         return root;

        if (d == 0 || d == 1) {
            TreeNode newroot = new TreeNode(v);
            newroot.left = d == 1 ? root : null;
            newroot.right = d == 0 ? root : null;
            return newroot;
        }
        if (root != null && d >= 2) {
            root.left= addOneRow(root.left,  v, d > 2 ? d - 1 : 1);
            root.right= addOneRow(root.right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
}