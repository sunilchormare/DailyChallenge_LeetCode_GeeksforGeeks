class Solution {
private:
    static constexpr int MAX = 100005;
    static inline int dp[MAX];
    static inline int pref[MAX];

    static inline int init = []() {
        for (int i = 100; i < MAX; i++) {
            int d1 = i % 10;
            int d2 = (i / 10) % 10;
            int d3 = (i / 100) % 10;

            int wave = (d2 > max(d3, d1)) | (d2 < min(d3, d1));

            dp[i] = dp[i / 10] + wave;
            pref[i] = pref[i - 1] + dp[i];
        }
        return 0;
    }();

public:
    int totalWaviness(int A, int B) { return pref[B] - pref[A - 1]; }
};