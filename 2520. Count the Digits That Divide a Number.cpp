class Solution {
public:
    int countDigits(int num) {
        
        int ans = 0;
        int temp = num;
        while(temp > 0){
            
            int rem = temp % 10;
            temp /= 10;
            
            if(!(num % rem)) ans++;
        }
        
        return ans;
        
    }
};