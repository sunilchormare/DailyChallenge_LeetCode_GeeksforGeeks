class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(begin(clips), end(clips));
        int res = 0;
        for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
            for (; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if (st == end) return -1;
        }
        return res;
    }
};