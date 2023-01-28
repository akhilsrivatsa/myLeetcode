class SummaryRanges {
public:
    map<int ,int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        mp[value] = 1;
    }
    
    vector<vector<int>> getIntervals() {

        vector<vector<int>> ans;

        int st = -1;
        int prev = -1;
        int end = -1;

        for(auto it = mp.begin(); it != mp.end() ; it++){

           if(st == -1){
               st = it -> first;
               prev = st;
               continue;
           }

           if(it->first - 1 == prev){
              prev = it -> first;
           }else{
               ans.push_back({st, prev});
               st = it -> first;
               prev = st;
           }

        }
         ans.push_back({st, prev});

        return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */