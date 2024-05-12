class LUPrefix {
public:
    unordered_map<int,int> map;
    int i=1;
    int sz=0;
    LUPrefix(int n) {
        sz=n;
    }
    
    void upload(int video) {
        map[video]=1;
        if(video==i)i++;
    }
    
    int longest() {
        while(map[i])i++;
        return i-1;
    }
};