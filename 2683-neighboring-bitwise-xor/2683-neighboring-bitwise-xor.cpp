class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for (int x: derived) {
            xr = xr ^ x;
        }
        return xr == 0; 
    }
};