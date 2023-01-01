class Solution {
public:
     vector<int> getP(){
        
        int sz = 10e5;
        
        vector<int> ans(sz, 0);
        vector<int> primes;
        
        for(int i = 2; i < sz; i++){
            
            if(!ans[i]){
                //cout << i << endl;
                primes.push_back(i);
                int p = i;
                for(int div = 2 ; p * div < sz ; div++){
                    ans[p * div]  = 1;
                }
            }
        }
        
        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        
        vector<int> primes = getP();
    
        vector<int> ans;
        int f = -1;
        int s = -1;
        int diff = INT_MAX;
        bool start = false;
        
        for(int i = 0; i < primes.size(); i++){
            //cout << primes[i] << endl;
            
            if(primes[i] > right){
                break;
            }
            
            if(start == false && left <= primes[i]){
                start = true;
                continue;
            }
            if(start){
                
                if(primes[i] - primes[i - 1] < diff){
                    diff = primes[i] - primes[i - 1];
                    f = primes[i - 1];
                    s = primes[i];
                }
            }
            
        }
        ans.push_back(f);
        ans.push_back(s);
        return ans;
    
        
    }
};