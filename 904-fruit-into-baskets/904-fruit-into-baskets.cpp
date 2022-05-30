class Solution {
public:
    int totalFruit(vector<int>& tree) {
       unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) 
        {
       // cout<<" Inside L : "<<" i : "<<i<<"  "<<" j : "<<j<<endl;    
            count[tree[j]]++;
            if (count.size() > 2) 
            {
                if (--count[tree[i]] == 0) 
                    count.erase(tree[i]);
                
                i++;
            }
        }
        //cout<<" i : "<<i<<"  "<<" j : "<<j;
        return j - i; 
    }
};