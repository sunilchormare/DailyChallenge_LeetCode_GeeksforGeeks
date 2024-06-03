class Solution {
    class Node{
        int ori;
        int change;
        int pos;

        public Node(int ori, int change, int pos) {
            this.ori = ori;
            this.change = change;
            this.pos = pos;
        }
    }
    
    public int[] sortJumbled(int[] mapping, int[] nums) {
        List<Node> list = new ArrayList<>();
        
        for (int i = 0; i<nums.length; i++){
            list.add(new Node(nums[i], modify(mapping, nums[i] + ""), i));
        }
        
        Collections.sort(list, (a, b) -> a.change == b.change ?  a.pos - b.pos : a.change - b.change);
        
        int[] res = new int[nums.length];
        for(int i=0; i<list.size(); i++){
            res[i] = list.get(i).ori;
        }
        
        return res;
    }
    
    private int modify(int[] mapping, String s) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            chars[i] = (char) (mapping[chars[i] - '0'] + '0');
        }

        return Integer.parseInt(new String(chars));
    }
}