class Solution {
public:
    int maxLength(vector<string>& arr) {
          return process(arr, "", 0);
    }
    int process(vector<string>& arr, string soFar, int index) {
        if (index > arr.size()) return 0;
        set<char> set;
        for(char c: soFar) {
            if(set.count(c)) return 0;
            set.insert(c);
        }
        int maxi = soFar.length();
        for(int i = index; i < arr.size(); i++) {
            maxi = max(maxi, process(arr, soFar + arr[i], i + 1));
        }
        return maxi;
    }
};