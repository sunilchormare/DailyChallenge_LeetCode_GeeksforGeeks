class RLEIterator {
public:
    
    int curInd;
    vector<int> seq;
    
    RLEIterator(vector<int>& A) {
        seq = A;
        curInd = 0;
    }
    
    int next(int n) {
        while (curInd < seq.size()){
            if (seq[curInd]>=n){
                seq[curInd]-=n;
                return seq[curInd+1];
            }else{
                n -= seq[curInd];
                curInd += 2;
            }
        }
        return -1;
    }
};