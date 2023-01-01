class Solution {
public:
    vector<int> getP(){
        
        int sz = 10e5;
        
        vector<int> ans(sz, 0);
        vector<int> primes;
        
        for(int i = 2; i < sz; i++){
            
            if(!ans[i]){
                primes.push_back(i);
            }else{
                int p = i;
               for(int div = 2 ; p * div < sz ; div++){
                    ans[p * div]  = 1;
                }
            }
        }
        
        return primes;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        
        vector<int> primes = getP();
        
        
        int k = 0;
        int ans = 0;
        map<int , int> mp;

        for(int num : nums){

            int mul = num;
            int k = 0;
            while(mul > 1){

                 while(mul > 1 && !(mul % primes[k])){

                        if(!mp[primes[k]]){
                            mp[primes[k]] = 1;
                            ans++;
                        }
                       mul = mul / primes[k];
                }
                k++;
             }
        }

         return ans;
        
    }
};