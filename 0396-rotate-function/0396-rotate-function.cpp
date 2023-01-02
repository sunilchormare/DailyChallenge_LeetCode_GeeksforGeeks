class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int allSum = 0;
int len = A.size();
int F = 0;
for (int i = 0; i < len; i++) {
    F += i * A[i];
    allSum += A[i];
}
int maxi = F;
for (int i = len - 1; i >= 1; i--) {
    F = F + allSum - len * A[i];
    maxi = max(F, maxi);
}
return maxi;
    }
};