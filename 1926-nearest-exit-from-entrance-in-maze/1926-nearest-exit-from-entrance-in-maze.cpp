class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        
        queue<pair<int, int>> q;
        q.push(make_pair(entrance[0], entrance[1]));
        
        int count = 0;
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        
        while(!q.empty()){
            
            int x = q.size();
            for(int i = 0; i < x; i++){
                
            
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if(r < 0 || c < 0 || r == maze.size() || c == maze[0].size()){
                    
                    if(count == 1) continue;
                    return count - 1;
                }
                
                if(visited[r][c]) continue;
                
                visited[r][c] = 1;
                
                
                if(maze[r][c] == '+') continue;
                
                q.push(make_pair(r + 1, c));
                q.push(make_pair(r - 1, c));
                q.push(make_pair(r, c + 1));
                q.push(make_pair(r, c - 1));
                
            }
           
            count++;
            
        }
        
        return -1;
    }
};