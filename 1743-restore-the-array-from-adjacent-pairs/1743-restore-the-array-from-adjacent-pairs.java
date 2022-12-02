class Solution {
   public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] adjacentPair: adjacentPairs) {
            map.putIfAbsent(adjacentPair[0], new ArrayList<>());
            map.get(adjacentPair[0]).add(adjacentPair[1]);

            map.putIfAbsent(adjacentPair[1], new ArrayList<>());
            map.get(adjacentPair[1]).add(adjacentPair[0]);
        }
        Integer start = null, end = null;
        for (int key: map.keySet()) {
            if (map.get(key).size() == 1 && start == null) {
                start = key;
            } else if (map.get(key).size() == 1) {
                end = key;
            }
        }

        int[] resArr = new int[adjacentPairs.length + 1];
        dfs(resArr, map, start, end, new HashSet<>(), 0);
        return resArr;
    }
    
    public void dfs(int[] resArr, Map<Integer, List<Integer>> map, Integer start, Integer end, Set<Integer> visited, int index) {
        resArr[index] = start;
        if (visited.contains(start) || start == end) {
            return;
        }
        visited.add(start);
        for (int neigh: map.get(start)) {
            if (!visited.contains(neigh)) {
                dfs(resArr, map, neigh, end, visited, index + 1) ;
            }
        }
    }
}