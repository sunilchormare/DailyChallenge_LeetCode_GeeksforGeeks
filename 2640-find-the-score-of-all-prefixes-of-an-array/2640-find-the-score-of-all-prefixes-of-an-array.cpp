class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
      vector<long long> pre;
      long long m = 0, s = 0;
      for(int x : nums) {
          m = max(m, (long long)x);
          s += x + m;
          pre.push_back(s);
      }
      return pre;
  }
};