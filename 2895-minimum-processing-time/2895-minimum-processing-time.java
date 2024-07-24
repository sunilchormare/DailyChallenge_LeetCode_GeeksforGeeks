class Solution {
    public int minProcessingTime(List<Integer> pro, List<Integer> tasks) {
        Collections.sort(tasks);
        Collections.sort(pro, Collections.reverseOrder());
        int ans=Integer.MIN_VALUE;
        int j=0;
        for(int i=0;i<pro.size();i++){
            for(int k=1;k<=4;k++){
                ans=Math.max(ans,pro.get(i)+tasks.get(j));
                j++;
            }
        }
        return ans;
    }
}