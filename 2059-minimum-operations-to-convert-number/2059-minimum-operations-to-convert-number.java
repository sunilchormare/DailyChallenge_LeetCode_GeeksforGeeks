class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
           Queue<Integer> q=new LinkedList<>();
        q.add(start);
        int step=0;
        boolean[] visited=new boolean[1001];
        visited[start]=true;
        while(!q.isEmpty()) {
            step++;
            int size=q.size();
            for(int ct=0;ct<size;ct++) {
                int cur=q.poll();
                for(int i=0;i<nums.length;i++) {
                    if(cur+nums[i]==goal||cur-nums[i]==goal||(cur^nums[i])==goal) return step;
                    if(cur+nums[i]>=0&&cur+nums[i]<=1000&&!visited[cur+nums[i]]) {
                        q.offer(cur+nums[i]);
                        visited[cur+nums[i]]=true;
                    } 
                    if(cur-nums[i]>=0&&cur-nums[i]<=1000&&!visited[cur-nums[i]]) {
                        q.offer(cur-nums[i]);
                        visited[cur-nums[i]]=true;
                    }
                    if((cur^nums[i])>=0&&(cur^nums[i])<=1000&&!visited[cur^nums[i]]) {
                        q.offer(cur^nums[i]);
                        visited[cur^nums[i]]=true;
                    }
                }
            }
        }
        return -1;
    }
}