class TimeMap {
 Map<String,Map> map = new HashMap<>();
    Map<Integer,String> timeMap = new HashMap<>();
    /** Initialize your data structure here. */
    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        Map<Integer,String> tempMap = map.getOrDefault(key,new HashMap<Integer,String>());
        tempMap.put(timestamp,value);
        map.put(key,tempMap);
    }
    
    public String get(String key, int timestamp) {
        if(!map.containsKey(key)) return "";
        else{
            Map<Integer,String> tempMap = map.get(key);
            for(int i = timestamp;i>=0;i--){
                if(tempMap.containsKey(i)){
                    return tempMap.get(i);
                }
            }
            return "";
        }
    }
}
