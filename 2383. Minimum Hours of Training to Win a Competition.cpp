class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        
        int t = 0;
        int hrs = 0;
        for(int num : energy ){
            t += num;
        }
        
        if(t >= initialEnergy){
              hrs = t - initialEnergy + 1;
        }
        cout << hrs << endl;
      
        
        for(int ex : experience){
          
            if(initialExperience <= ex){
                int req =  ex - initialExperience + 1;
                initialExperience += req;
                hrs += req;
                
            }
            
            initialExperience  += ex;
            
        }
        return hrs;
        
    }
};