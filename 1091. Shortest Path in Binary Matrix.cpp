class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) return -1;
        int x = 0;

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        while(!q.empty()){


            int sz = q.size();
            x++;
            for(int i = 0; i < sz; i++){

                pair<int, int> p = q.front();
                q.pop();

                int xc = p.first, yc = p.second;

                if(xc == grid.size() - 1 && yc == grid[0].size() - 1) return x;

                if(xc < 0 || yc < 0 || xc >= grid.size() || yc >= grid[0].size()){
                    continue;
                }


                if(grid[xc][yc] == 1) continue;

                grid[xc][yc] = 1;

                q.push(make_pair(xc + 1, yc));
                q.push(make_pair(xc - 1, yc));
                q.push(make_pair(xc, yc + 1));
                q.push(make_pair(xc, yc - 1));
                q.push(make_pair(xc + 1, yc +1));
                q.push(make_pair(xc - 1, yc  - 1));
                q.push(make_pair(xc - 1, yc  + 1));
                q.push(make_pair(xc + 1, yc  - 1));
            }
        }
        return -1;
        
    }
};