class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int count = 1;
        for(int i = 0;i<candyType.size();i++){
            for(int j = i+1;j<candyType.size();j++){
                if(candyType[i]==candyType[j]){
                    continue;
                }
                else if(candyType[i]!=candyType[j]){
                    i=j;
                    i--;
                    count++;
                    break;
                }
            }
        }
        int n = candyType.size()/2;
        if(count == n){
            return n;
        }
        else{
            return min(count,n);
        }
    }
};