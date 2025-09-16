class Solution {
public:
        vector<int> replaceNonCoprimes(vector<int>& A) {
        vector<int> res;
        for (int a: A) {   
            while (true) {   
                int x = gcd(res.empty() ? 1 : res.back(), a);
                if (x == 1) break; // co-prime
                a *= res.back() / x;
                res.pop_back();
            }
            res.push_back(a);
        }
        return res;
    }
};