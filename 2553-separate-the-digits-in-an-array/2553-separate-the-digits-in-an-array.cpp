class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
              vector<int> ans;
        for (int num : nums) {
            vector<int> temp; 
            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            for (int j = temp.size() - 1; j >= 0; j--) {
                ans.push_back(temp[j]);
            }
        }
         vector<int> result(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans[i];
        }
        return result;
 
    }
};