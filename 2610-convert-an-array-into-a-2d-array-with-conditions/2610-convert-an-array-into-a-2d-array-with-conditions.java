class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
         Map<Integer,Integer> m = new HashMap<>(); 
         List<List<Integer>> list = new ArrayList<>(); 
        int max=0; 
        for(int i=0;i<nums.length;i++) 
        { 
            m.put(nums[i],m.getOrDefault(nums[i],0)+1); 
            max = Math.max(max,m.get(nums[i])); 
        } 
        for(int i=0;i<max;i++) 
        { 
            list.add(new ArrayList<Integer>()); 
        } 
        for (Map.Entry<Integer,Integer> entry : m.entrySet()) 
        { 
            for(int i=0;i<entry.getValue();i++) 
            { 
                list.get(i).add(entry.getKey()); 
            } 
        } 
        return list; 
    
    }
}