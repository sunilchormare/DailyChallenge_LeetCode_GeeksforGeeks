class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> ump;
    for(int itr = 0; itr < target.size(); itr++){
        ump[target[itr]]++;
        ump[arr[itr]]--;
    }        
    for(int itr = 0; itr < ump.size(); itr++){
        if(ump[itr] != 0) return false;
    }
    return true;
    }
};