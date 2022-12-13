 //Stern Brocot Tree BFS

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
      if (n==1) return {};
        queue<tuple<int,int,int,int>> q;
        vector<string> res;
        q.emplace(0, 1, 1, 1);
        while(!q.empty()) {
            auto [num1, den1, num2, den2] = q.front();
            int num = num1 + num2;
            int den = den1 + den2;
            q.pop();
            res.push_back(to_string(num)+"/"+to_string(den));
            if (den + den1 <= n) {
                q.emplace(num1,den1,num,den);
            }
            if (den + den2 <= n) {
                q.emplace(num,den,num2,den2);
            }
        }
        return res;   
    }
};