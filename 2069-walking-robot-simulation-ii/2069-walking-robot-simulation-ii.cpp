class Robot {
public:
    Robot(int width, int height){
        directions["East"] = {1,0};
        directions["North"] = {0,1};
        directions["South"] = {0,-1};
        directions["West"] = {-1,0};
        
        row = col = 0;
        W = width;
        H = height;
        paramter = 2*(H+W-2);
        order = {"East", "North", "West", "South"};
        curr_dir = 0;
    }
    
    void step(int num) {
        if(row == 0 && col == 0){
            num = num%paramter;
            if(num == 0) curr_dir = 3;
        }
        row += num * directions[order[curr_dir]].first;
        col += num * directions[order[curr_dir]].second;
        bool exceeded = true;

        if(row >= W){
            num = row - (W-1);
            row = W-1;
        }
        else if(col >= H){
            num = col - (H-1);
            col = H-1;
        }
        else if (row < 0){
            num = abs(row);
            row = 0;
        }
        else if(col < 0){
            num = abs(col);
            col = 0;
        }
        else{
           exceeded = false; 
        }


        if(exceeded){
            curr_dir = (curr_dir + 1)%4;
            step(num);
        }
    }
    
    vector<int> getPos() {
        return {row, col};
    }
    
    string getDir() {
        return order[curr_dir];
    }
    unordered_map<string, pair<int,int>> directions;
    int curr_dir;
    int row, col;
    int W, H;
    int paramter;
    vector<string> order;
};