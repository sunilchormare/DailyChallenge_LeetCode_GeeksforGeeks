class Solution {
public:
    bool isPossibleDivide(vector<int> A, int k) {
        map<int, int> c;
        for (int i : A) c[i]++;
        queue<int> start;
        int last_checked = -1, opened = 0;
        for (auto it : c) {
            int i = it.first;
            if (opened > 0 && i > last_checked + 1 || opened > c[i]) return false;
            start.push(c[i] - opened);
            last_checked = i, opened = c[i];
            if (start.size() == k) {
                opened -= start.front();
                start.pop();
            }
        }
        return opened == 0;
    }
};