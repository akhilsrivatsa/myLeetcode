class Solution {
public:



    bool isBiPartite(int n, map<int, vector<int>> &mp, vector<int> &v, int node){
        
        
        queue<int> q;
        vector<int> color( n + 1);
        color[node] = 1;
        q.push(node);
        
        while(!q.empty()){


            int x = q.front();
            q.pop();
            if(v[x]) continue;
            v[x] = 1;
            for(int i = 0; i < mp[x].size(); i++){
                int ele = mp[x][i];
                if(v[ele]) continue;

                if(color[ele] == color[x]){
                    return false;
                }
                color[ele] = color[x] == 1 ? 2 : 1;
                cout<<ele<<" "<< color[ele]<<endl;
                q.push(ele);
            }
                
        }

        return true;


        


    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        map<int, vector<int>> mp;
        vector<int> visited(n + 1);
       

        for(int i =  0; i < dislikes.size(); i++){

            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        } 


        for(int i = 1; i <=n ; i++){
            if(!visited[i]){
                
              if(!isBiPartite(n, mp, visited, i)){
                    return false;
                }       
           }
           
        }
        return true;
        
    }
};