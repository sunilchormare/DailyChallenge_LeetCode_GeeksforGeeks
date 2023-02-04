class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        // long long res=0;
        // for(int i=0;i<r.size();++i)
        // {
        //     for(int j=i+1;j<r.size();++j)
        //     {
        //         double a=double(r[i][0])/double(r[i][1]); //cout<<a<<" ";
        //         double b=double(r[j][0])/double(r[j][1]); //cout<<b<<" ";
        //         if(a==b)
        //             res++;
        //     }
        // }
        // return res;
        
        	long long result = 0;
	unordered_map<double, int> mp;

	for (auto& rect : r)
	{
		double ratio = (double)rect[0] / rect[1];
		if(mp.find(ratio) != mp.end()) result += mp[ratio];
		mp[ratio]++;
	}

	return result;
    }
};