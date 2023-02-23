class Solution {
public:
     set<pair<int, int>> s;
    void dfs(int node, vector<bool> &vis, unordered_map<int , vector<int>>&mp, int src){
        
        if(vis[node]){
            return;
        }
        vis[node] = 1;

        for(int i = 0; i < mp[node].size(); i++){
            dfs(mp[node][i], vis, mp, src);
        }
        //cout << src << " " << node << endl;
        s.insert({src, node});
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<bool> ans(queries.size());
        unordered_map<int , vector<int>> mp;
        for(int i = 0; i < prerequisites.size(); i++){
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            mp[src].push_back(dest);
        }
        for(int i = 0; i < numCourses; i++){
            vector<bool> vis(numCourses, false);
            dfs(i, vis, mp, i);
        }

        //cout << "Queries: " << endl;

        for(int i = 0; i < queries.size(); i++){

            int c1 = queries[i][0];
            int c2 = queries[i][1];
            //cout << c1 << " " << c2 << endl;

            if(s.find({c1, c2}) != s.end()){
                 ans[i] = true;
            }
            else ans[i] = false;
        }

        return ans;
        
        
        
    }
};