class Solution {
public:
    string deletions(string s){
        
        while(true){
            bool found = false;

            for(int i = 0; i < s.size(); i++){

                int count = 1;
                int st = i;
                while(i != s.size() - 1 && s[i] == s[i + 1]){
                    i++;
                    count++;
                }

                if(count >= 3){
                    found = true;
                     s = s.substr(0, st) + s.substr(i + 1);
                }

            }
            
            if(!found){
                break;
            }
        }

       return s;

    }
    int findMinStep(string board, string hand) {

        int count = 0;
        queue<pair<string, string>> q;
        unordered_map<string, int> dict;

        q.push(make_pair(board, hand));

        while(!q.empty()){

            int x = q.size();
            
            for(int i = 0; i < x; i++){

                pair<string, string> p = q.front();
                q.pop();

                string b = p.first;
                string h = p.second;
               if(b.length() == 0){
                    return -1;
                }
                for(int k = 0; k < h.size(); k++){
                    for(int m = 0; m <= b.size(); m++){

                       if(m < b.size() - 1 && h[k] != b[m] && h[k] != b[m + 1]) continue;
                       string pm = b.substr(0, m) + h[k] + b.substr(m);
                       string res = deletions(pm);
                       if(res.length() == 0){
                           return count + 1;
                       }
                       if(dict[res]){
                           continue;
                       }
                       dict[res] = 1;
                       q.push(make_pair(res,  h.substr(0, k) + h.substr(k + 1)));
                    }
                }

                
            }

            count++;
        }
        return -1;
        
    }
};