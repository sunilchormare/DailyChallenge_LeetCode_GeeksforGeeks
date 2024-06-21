class Solution {
public:
    int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) {
           int sum = 0, maxWindow = 0, window = 0;
        
        for (int i = 0; i < cs.size(); ++i) 
        {
            sum += grumpy[i] == 0 ? cs[i] : 0;
            
            window += grumpy[i] == 1 ? cs[i] : 0;
            
            if (i >= X) window -= grumpy[i - X] == 1 ? cs[i - X] : 0;
            
            maxWindow = max(maxWindow, window);
        }
        return sum + maxWindow;
    }
};