class DataStream {
    Queue<Integer> q=new LinkedList<>();
    int k;
    int value;
    public DataStream(int value, int k) {
        this.k=k;
        this.value=value;
    }
    
    public boolean consec(int num) {
        if(num!=value){q.clear();return false;}
        if(num==value){
            q.add(num);
        }
        if(q.size()==k){
            q.poll();
            return true;
        }
        return false;
    }
}