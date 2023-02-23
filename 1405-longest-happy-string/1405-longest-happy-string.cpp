class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        string curr = "";
        priority_queue<pair<int , char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        while(!pq.empty()){

            pair<int, char> p = pq.top();
            pq.pop();

            if(curr.size() >= 2){

                if(curr[curr.size() - 1] == curr[curr.size() - 2] && (curr[curr.size() - 1] == p.second)){

                    if(pq.empty()){
                        break;
                    }
                     pair<int, int> pair = pq.top();
                     pq.pop();
                     pq.push(p);
                     p = pair;
                }
                 curr += p.second;
                 if(p.first > 1){
                     pq.push({p.first - 1, p.second});
                 }

            }else{
                curr += p.second;
                if(p.first > 1){
                    pq.push({p.first - 1, p.second});
                }
            }
        }
        return curr;
        
    }
};