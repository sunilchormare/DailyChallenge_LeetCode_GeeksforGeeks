class FrequencyTracker {
public:
    unordered_map<int, int> mp;   //store number & frequency count
    unordered_map<int, int> mps;  //store frequency & count number whose frequecny is same
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number) != mp.end()){
            mps[mp[number]]--;
        }
        mp[number]++;
        mps[mp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end() && mp[number] > 0){
            mps[mp[number]]--;
            mp[number]--;
            mps[mp[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return (mps[frequency] > 0);
    }
};