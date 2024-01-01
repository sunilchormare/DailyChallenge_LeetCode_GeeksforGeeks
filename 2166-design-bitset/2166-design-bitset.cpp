class Bitset {
public:
     int a = 0, sz = 0, cnt = 0, isFlip = 0;
    string s;
    Bitset(int size) {
        sz = size;
        s = string(sz, '0');
    }
    
    void fix(int idx) {
        if (s[idx] == '0' + isFlip) {
            s[idx] = '1' + '0' - s[idx];
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if (s[idx] == '1' - isFlip) {
            s[idx] = '1' + '0' - s[idx];
            cnt--;
        }
    }
    
    void flip() {
        isFlip ^= 1;
        cnt = sz - cnt;
    }
    
    bool all() {
        return cnt == sz;
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        if (isFlip) {
            string s2 = s;
            for (auto& c: s2)
                c = '0' + '1' - c;
            return s2;
        }
        return s;
    }
};

