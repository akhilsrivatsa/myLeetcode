class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {


        unordered_map<int, vector<pair<int , double>>> mp;
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0);

        for(int i = 0; i < edges.size(); i++){

            int src = edges[i][0];
            int dst = edges[i][1];
            float prob = succProb[i];

            mp[src].push_back(make_pair(dst, prob));
            mp[dst].push_back(make_pair(src, prob));

        }

        dist[start] = INT_MAX;
        pq.push(make_pair(1.0, start));


        while(!pq.empty()){

            pair<double ,int> p = pq.top();
            pq.pop();

            for(int i = 0; i < mp[p.second].size(); i++){
                double currDist = p.first; 
                double addDist = mp[p.second][i].second;
                double neighbour  = mp[p.second][i].first;
                double newDist = currDist * addDist;
                if(newDist > dist[neighbour]){
                    dist[neighbour] = newDist;
                     pq.push(make_pair(newDist, neighbour));
                }
            }
        }
        return dist[end] == INT_MAX ? 0 : dist[end];
        
    }
};