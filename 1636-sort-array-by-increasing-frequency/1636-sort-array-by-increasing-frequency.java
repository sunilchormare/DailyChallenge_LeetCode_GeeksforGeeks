class Solution {
   public int[] frequencySort(int[] nums) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        ArrayList<Integer> al = new ArrayList<>();
        for(int a : nums) 
        {
            al.add(a);
            hm.put(a,hm.getOrDefault(a,0)+1);
        }
        Collections.sort(al,(a,b)->{
             int f1 = hm.get(a);
            int f2 = hm.get(b);
            if(f1!=f2) return f1-f2;
            return b-a;
         });
        int i=0;
        int arr[] = new int[al.size()];
        for(int val : al) arr[i++] = val;
        return arr;
    }
}