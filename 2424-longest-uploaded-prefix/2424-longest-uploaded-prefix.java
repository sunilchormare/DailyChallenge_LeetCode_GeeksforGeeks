class LUPrefix {
    Set<Integer> set;
    int max=0;
    public LUPrefix(int n) {
        set=new HashSet<>();
    }
    public void upload(int video) {
        set.add(video);
        while(set.contains(max+1)) max++;
    }
    public int longest() {
        return max;
    }
}