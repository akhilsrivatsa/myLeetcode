class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char, string>m1;
        unordered_map<string, char>m2;
        
        stringstream ss(str);
        string s;
        int i = 0;
        
        while (ss >> s) {
            if (m1.find(pattern[i]) != m1.end()) {
                if (m1[pattern[i]] != s)
                    return false;
            }
            
            if (m2.find(s) != m2.end()) {
                if (m2[s] != pattern[i])
                    return false;
            }
            m1[pattern[i]] = s;
            m2[s] = pattern[i];
            i++;
        }
        
        if (i != pattern.length())
            return false;
        
        return true;
    }
};