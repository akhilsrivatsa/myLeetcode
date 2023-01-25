class Solution {
public:
   void fillDist(vector<int> &vis, int node, vector<int> &edges){

        queue<int> q;
        q.push(node);
        int currentDist = 0;
        while(!q.empty()){
            int x = q.size();
           for(int i = 0; i < x; i++){
                int n = q.front();
                q.pop();
               // cout << n << " " << currentDist << endl;
                vis[n] = currentDist;
                int neigh = edges[n];
                if(neigh != -1 && vis[neigh] == -1){
                    q.push(neigh);
                }
            }
            currentDist++;
        }
      
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int minLen = INT_MAX;
        int ans = -1;
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);
        fillDist(dist1, node1, edges);
        fillDist(dist2, node2, edges);

        for(int i = 0; i < dist1.size(); i++){
           // cout << dist1[i] << " " << dist2[i]  << endl;

            if(dist1[i] < 0|| dist2[i] < 0) continue;
            int maxD = max(dist1[i], dist2[i]);

            if(minLen > maxD){
                minLen = maxD;
                ans = i;
            }
        }

        return ans;
    }
};