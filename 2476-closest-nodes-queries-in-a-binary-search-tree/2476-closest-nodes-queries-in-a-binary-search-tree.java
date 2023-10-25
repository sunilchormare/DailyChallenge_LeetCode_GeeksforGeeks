class Solution {
    private List<Integer> order = new ArrayList<>();
    
    public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
        List<List<Integer>> res = new ArrayList<>();
        inOrder(root);

        for(int query: queries){
            res.add(excecuteQuerrySearch(query));
        }

        return res;
    }


    private void inOrder(TreeNode root){
        if(root == null)return;

        inOrder(root.left);
        order.add(root.val);
        inOrder(root.right);
    }


    private List<Integer> excecuteQuerrySearch(int query){
        List<Integer> queryRes = new ArrayList<>();

        int low = 0, high = order.size() - 1;
        int smallestNo = -1, largestNo = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(order.get(mid) == query){
                smallestNo = order.get(mid);
                break;
            }else if(order.get(mid) < query){
                smallestNo = order.get(mid);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        low = 0; 
        high = order.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(order.get(mid) == query){
                largestNo = order.get(mid);
                break;
            }else if(order.get(mid) > query){
                largestNo = order.get(mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        queryRes.add(smallestNo);
        queryRes.add(largestNo);

        return queryRes;
    }
}