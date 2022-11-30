class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        for(int i = 0; i<arr.size(); i++) {
            //storing the number of occurances of elements
            mp[arr[i]]++;
        }

        vector<int> freq;
        for(auto i:mp) {
            //pushing the occurances into frequency vector
            freq.push_back(i.second);
        }

        //sorting the frequency vector
        sort(freq.begin(), freq.end());

        for(int i = 0; i<freq.size()-1; i++) {
            //checking if 2 consequent elements are equal
            if(freq[i] == freq[i+1])
                return false;
        }

        return true;

    }
};