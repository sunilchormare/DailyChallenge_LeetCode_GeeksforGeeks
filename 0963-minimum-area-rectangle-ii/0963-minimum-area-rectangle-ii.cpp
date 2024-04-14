class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        double _Area, minArea = 0.0;
        if (points.size() < 4){
            return 0;
        }
        int x0, y0;
        int x1, y1;
        int x2, y2;
        int x3, y3;
        int Lx1, Ly1;
        int Lx2, Ly2;
        for(int i = 0; i < points.size() - 3; i ++){

            x0 = points[i][0];
            y0 = points[i][1];

            for (int j = i + 1; j < points.size(); j ++){
                x1 = points[j][0];
                y1 = points[j][1];
                for (int k = j + 1; k < points.size(); k ++){
                    x2 = points[k][0];
                    y2 = points[k][1];

                    Lx1 = x1 - x0;
                    Ly1 = y1 - y0;
                    
                    Lx2 = x2 - x0;
                    Ly2 = y2 - y0;

                    int dotProd = Lx1 * Lx2 + Ly1 * Ly2;
                    if (dotProd != 0){
                        continue;
                    }
                    bool skip = true;
                    for (int n = 0; n < points.size(); n ++){
                        x3 = points[n][0];
                        y3 = points[n][1];
                        if ((x3 == x0 + Lx1 + Lx2) && (y3 == y0 + Ly1 + Ly2)){
                            skip = false;
                            break;
                        }
                    }
                    if(skip == true){
                        continue;
                    }
                    _Area = (double)abs(Lx1 * Ly2 - Ly1 * Lx2);

                    if (minArea == 0.0){
                        minArea = _Area; 
                    }else{
                        minArea = minArea < _Area ? minArea : _Area;
                    }
                }
            }
        }
        return minArea;
    }
};