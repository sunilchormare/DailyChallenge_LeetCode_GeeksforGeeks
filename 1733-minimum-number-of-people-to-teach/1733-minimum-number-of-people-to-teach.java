class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Map<Integer, Set<Integer>> languagesMap = new HashMap<>();
        for(int i = 0; i < languages.length; i++) {
            languagesMap.put(i + 1, new HashSet<>());
            for(int l : languages[i]) {
                languagesMap.get(i + 1).add(l);
            }
        }
        boolean[] alreadyCan = new boolean[friendships.length];
        for(int j = 1; j <= n; j++) {
            for(int i = 0; i < friendships.length; i++) {
                if(languagesMap.get(friendships[i][0]).contains(j) && languagesMap.get(friendships[i][1]).contains(j)) {
                    alreadyCan[i] = true;
                }
            }            
        }
        int minTeach = Integer.MAX_VALUE;
        for(int i = 1; i <= n; i++) {
            Set<Integer> teachSet = new HashSet<>();
            for(int j = 0; j < friendships.length; j++) {
                if(alreadyCan[j]) continue;
                if(!languagesMap.get(friendships[j][0]).contains(i)) teachSet.add(friendships[j][0]);
                if(!languagesMap.get(friendships[j][1]).contains(i)) teachSet.add(friendships[j][1]);
            }
            minTeach = Math.min(teachSet.size(), minTeach);
        }
        return minTeach;
    }
}