class Solution {
public:

    void dfs(vector<vector<int>>& rooms, vector<int>& visited, map<int, vector<int>> &mp, int node){

        if(visited[node]) return;

        visited[node] = 1;

        for(int i = 0; i < mp[node].size(); i++){
            dfs(rooms, visited, mp, mp[node][i]);
        }


    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        map<int, vector<int>> mp;
        vector<int> visited(rooms.size());
        
        for(int i = 0; i < rooms.size() ; i++){
            mp[i] = rooms[i];
        }

        dfs(rooms, visited, mp, 0);

        for(int i = 0; i < visited.size(); i++){

            if(!visited[i]) return false;
        }
        return true;





        
    }
};