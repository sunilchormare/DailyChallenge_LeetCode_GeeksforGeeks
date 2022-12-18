class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        if(t.size()==1) return {0};
        vector<int> retVec(t.size(),0);
        stack<int> mStack;
        for(int i = 0;i<t.size();++i) {
            while(!mStack.empty()&&t[mStack.top()]<t[i]) {
                retVec[mStack.top()] = i-mStack.top();
                mStack.pop();
            }
            mStack.push(i);
        }
        return retVec;
        
    }
};