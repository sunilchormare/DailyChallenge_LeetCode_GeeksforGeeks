class SmallestInfiniteSet {

    TreeSet<Integer> addedBackSet;
    int curMinTracker;
    
    public SmallestInfiniteSet() {
        this.addedBackSet = new TreeSet<>();
        this.curMinTracker = 1;
    }
    
    public int popSmallest() {
        if(!addedBackSet.isEmpty()) {
            int smallestValue = addedBackSet.first();
            addedBackSet.remove(smallestValue);
            return smallestValue;
        }
        return this.curMinTracker++;
    }
    
    public void addBack(int num) {
        if(num < this.curMinTracker) {
            addedBackSet.add(num);
        }
    }
}