class Solution {
public:

    int paths(vector<vector<int>>& grid, int startx, int starty, int endx, int endy, int ideal){

        
        if(startx < 0 || startx >= grid.size() || starty < 0 || starty >= grid[0].size() || grid[startx][starty] == -1){
            return 0;
        }

         ideal--;
        if(startx == endx && starty == endy){
            return ideal == 0;
        }
        int temp = grid[startx][starty];
        grid[startx][starty]  = -1;
        
        int down =  paths(grid, startx + 1, starty, endx, endy, ideal);
        int up =    paths(grid, startx - 1, starty, endx, endy, ideal);
        int right = paths(grid, startx, starty + 1, endx, endy, ideal);
        int left =  paths(grid, startx, starty - 1, endx, endy, ideal);

        grid[startx][starty]  = temp;
        return up + down + left + right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int startx = -1;
        int starty = -1;
        int endx = -1;
        int endy = -1;
        int ideal = 0;
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size()));

        for(int i = 0; i < grid.size(); i++){

            for(int j = 0; j < grid[i].size(); j++){

                if(grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }

                if(grid[i][j] == 2){
                    endx = i;
                    endy = j;
                }

                if(grid[i][j] != -1){
                    ideal++;
                }
            }
        }

        return paths(grid, startx, starty, endx, endy, ideal);
        
    }
};