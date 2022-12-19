class Solution {
public:
   int maxAreaHistogram(vector<int>& histogram){
    histogram.push_back(0); //sentinal node to check area again at last index.
    int area = 0, n = histogram.size();
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && histogram[st.top()] >= histogram[i]){
            int h = histogram[st.top()]; st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            area = max(area, h*(right-left-1));
        }
        st.push(i);
    }
    return area;
}

int maximalRectangle(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    vector<int> histogram(n, 0);
    for(int i=0; i<m; i++){
        //we are stacking up '1's to make histogram
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }
        //check area each time, cuz you need area even at smaller 1x blocks
        res = max(res, maxAreaHistogram(histogram));
    }
    return res;
}
};