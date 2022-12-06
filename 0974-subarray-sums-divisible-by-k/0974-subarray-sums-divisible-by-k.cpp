class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
         vector<int> m(K,0);
		m[0] = 1;
        int count = 0, sum = 0;
        for(int a : A) {
            sum = (sum + a) % K;
            if(sum < 0) sum += K;  
            count += m[sum];
            m[sum]++;
        }
        return count;
    }
};