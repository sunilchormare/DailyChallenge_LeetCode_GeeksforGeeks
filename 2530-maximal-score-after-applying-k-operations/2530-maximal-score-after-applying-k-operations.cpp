class Solution {
    public long maxKelements(int[] nums, int k) {
          PriorityQueue<Integer> pqq=new PriorityQueue<>((a,b)->b-a);
        for(int ii:nums){
            pqq.add(ii);
        }
        long max=0;
        for(int i=k;i>0;i--){
            int cq=pqq.poll();
            max+=cq;
            int f=(int)Math.ceil(cq/3.0);
            pqq.add(f);
        }
        return max;
    }
}