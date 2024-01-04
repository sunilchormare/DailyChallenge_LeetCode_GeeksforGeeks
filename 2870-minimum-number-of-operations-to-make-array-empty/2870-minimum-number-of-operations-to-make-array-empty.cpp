class Solution {
public:
  int minOperations(vector<int>& A) {
        unordered_map<int, int> count;
        for (int a : A) {
            ++count[a];
        }
        int res = 0;
        for (auto& [_, c] : count) {
            if (c == 1) return -1;
            res += (c + 2) / 3;
        }
        return res;
    }
};