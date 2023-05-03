class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& p, vector<int>& q) 
    {
        sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());

    sort(q.begin(),q.end());
    q.erase(unique(q.begin(),q.end()),q.end());
        
        vector<vector<int>> res;
	std::vector<int> cv;
	std::set_difference(std::begin(p), std::end(p), 
		std::begin(q), std::end(q), 
		std::back_inserter(cv));

   res.push_back(cv);

	std::vector<int> cv1;
	std::set_difference(std::begin(q), std::end(q), 
		std::begin(p), std::end(p), 
		std::back_inserter(cv1));


  res.push_back(cv1);
        
        return res;
    }
};