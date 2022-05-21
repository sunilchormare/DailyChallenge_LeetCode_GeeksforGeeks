class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    vector<int> need(amount+1, amount+1);
    need[0] = 0;
    for (int c : coins){
         //cout<<" c = "<<c<<endl; 
        for (int a=c; a<=amount; a++)
        {  need[a] = min(need[a], need[a-c] + 1);
         //cout<<" need[a] = "<<need[a]<<endl; 
        }
    }
    return need.back() > amount ? -1 : need.back();
    }
};