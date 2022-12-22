class Solution {
public:
    void dfs( map<int,vector<int>> &adj, int node, vector<int> &vis){
                
        
      
        if(vis[node]) return;
        vis[node] = 1;
        cout<<node<<endl;

        for(int i = 0; i < adj[node].size(); i++){

           
            dfs(adj, adj[node][i], vis);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        map<int , vector<int>> adj;
        vector<int> vis(isConnected.size());
        int tot = 0;
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[i].size(); j++){
               
                if(i != j && isConnected[i][j]){
                   
                    
                    adj[i].push_back(j);
                    
                }
            }
        }
     

        for(int i = 0; i < isConnected.size(); i++){

           
            if(vis[i] == 0){
                cout<<"here"<<endl;
                dfs(adj, i , vis);
                tot++;

            }
            
        }

        return tot;
        
    }
};