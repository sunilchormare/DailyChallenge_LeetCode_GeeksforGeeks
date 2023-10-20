class TweetCounts {
    Map<String, TreeMap<Integer, Integer>> map = new HashMap<>();
    public TweetCounts() { 
    }
    
    public void recordTweet(String tweetName, int time) {
        map.putIfAbsent(tweetName, new TreeMap<>());
        TreeMap<Integer, Integer> tm = map.get(tweetName);
        tm.put(time, tm.getOrDefault(time, 0) + 1);
    }
    
    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        List<Integer> res = new ArrayList<>();
        if (!map.containsKey(tweetName)) return res;
        TreeMap<Integer, Integer> tm = map.get(tweetName);
        int gap = 60;
        if (freq.equals("hour")) gap = 3600;
        else if (freq.equals("day")) gap = 3600 * 24;
        for (int start = startTime; start < endTime + 1; start += gap) {
            int sum = 0;
            int end = Math.min(start + gap, endTime + 1);
            Map<Integer, Integer> sm = tm.subMap(start, end);
            for (int value : sm.values()) sum += value;
            res.add(sum);
        }
        return res;
    }
}