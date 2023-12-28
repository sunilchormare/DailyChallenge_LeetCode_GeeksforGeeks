class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> _) {
        rects = _;
        for (auto& r : rects) {
            v.push_back(area(r) + (v.empty() ? 0 : v.back()));
        }
    }
    
    vector<int> pick() {
        // https://leetcode.com/problems/random-pick-with-weight/description/
        int rnd = rand() % v.back();
        auto it = upper_bound(v.begin(), v.end(), rnd);
        int idx = it - v.begin();
        
        // pick a random point in rect[idx]
        auto r = rects[idx];
        return {
            rand() % (r[2] - r[0] + 1) + r[0],
            rand() % (r[3] - r[1] + 1) + r[1]
        };
    }
};