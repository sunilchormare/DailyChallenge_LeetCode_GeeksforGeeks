class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> indice(2);
    if (num.size() < 2) return indice;
    int left = 0, right = num.size() - 1;
    while (left < right) {
        int v = num[left] + num[right];
        if (v == target) {
            indice[0] = left + 1;
            indice[1] = right + 1;
            break;
        } else if (v > target) {
            right --;
        } else {
            left ++;
        }
    }
    return indice;
    }
};