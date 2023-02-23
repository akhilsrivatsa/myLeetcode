class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int , vector<pair<int, int>>> mp;
        int mod = pow(10, 9) + 7;
        for(int i = 0 ; i < roads.size(); i++){

            int src  = roads[i][0];
            int dest = roads[i][1];
            int cost = roads[i][2];
            mp[src].push_back({dest, cost});
            mp[dest].push_back({src, cost});
        }

        vector<long long> dis(n, LONG_MAX);
        vector<long long> totWays(n, 0);

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long , long long>>> pq;
        pq.push(make_pair(0, 0));
        dis[0] = 0;
        totWays[0] = 1;

        while(!pq.empty()){

            pair<long long, long long> p = pq.top();
            pq.pop();
            long long dist = p.first;
            long long node = p.second;
            for(int i = 0; i < mp[node].size(); i++){

                pair<long long, long long> np = mp[node][i];
                long long currDist = np.second;
                long long nNode = np.first;
                long long newDist = dist + currDist;
                if(newDist < dis[nNode]){
                    dis[nNode] = newDist;
                    pq.push({newDist, nNode});
                    totWays[nNode] = (totWays[node]);
                }else if (newDist == dis[nNode]){
                    totWays[nNode] =   (totWays[nNode] + totWays[node]) % mod;
                }
            }
        }
        return totWays[n - 1];
    }
};