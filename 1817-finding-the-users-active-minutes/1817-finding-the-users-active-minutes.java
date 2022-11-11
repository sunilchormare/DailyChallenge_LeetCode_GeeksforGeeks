class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int i=0;i<logs.length;i++) {
            map.putIfAbsent(logs[i][0], new HashSet<>());
            map.get(logs[i][0]).add(logs[i][1]);
        }
        int[] res=new int[k];
        for(int key : map.keySet()) 
            res[map.get(key).size()-1]++;
        return res;
    }
}