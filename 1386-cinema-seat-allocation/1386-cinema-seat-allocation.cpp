class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
         int ans = n*2;
        
    unordered_map<int, char> m;
        
    for (auto r : reservedSeats)
        if (r[1] > 1 && r[1] < 10)
            m[r[0]] |= 1<<(r[1]-2);
        
    for (auto [row, seats] : m)
    {  
        bool left  = seats & 0b11110000;
        bool mid   = seats & 0b00111100;
        bool right = seats & 0b00001111;
            
        ans -= left && mid && right ? 2 : 1;
    }
        
    return ans;
    }
};