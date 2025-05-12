class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
    int cnt[10] = {};
    for (auto d : digits)
        ++cnt[d];
    for (int i = 1; i < 10; ++i)
        for (int j = 0; cnt[i] > 0 && j < 10; ++j)
            for (int k = 0; cnt[j] > (i == j) && k < 10; k += 2)
                if (cnt[k] > (k == i) + (k == j))
                    res.push_back(i * 100 + j * 10 + k);
    return res;
    }
};