class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        int rounds = 0;

        map<int, int> mp;
        for(int t : tasks){
            mp[t]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){

            int val = it -> second;
            cout << it ->first << " ";
            cout << val << endl;
            while(val > 1){

                if(val - 3 != 1 && val - 3 >= 0){
                    val = val - 3;
                }else{

                    val = val - 2;
                }
                rounds++;
            }

            if(val != 0) return -1;
        }

        return rounds;
        
    }
};