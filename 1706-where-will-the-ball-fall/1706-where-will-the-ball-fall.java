class Solution {

    private Integer helper(int[][] grid, Integer[][] dp, int i, int j ){
        
        if(i == grid.length - 1) return dp[i][j];
        
        if(j < 0 || j == grid[0].length) return -1;
        
        if(dp[i][j] != null) {
            
            System.out.println("val " + dp[i][j] + " i " + i + " j " + j );
            return dp[i][j];
        }
       
        if(grid[i][j] == 1){
           dp[i][j] = helper(grid, dp, i + 1, j + 1);
        }else {
              dp[i][j] = helper(grid, dp, i + 1, j - 1);
        
        }
        return dp[i][j];
        
    }
    
    public int[] findBall(int[][] grid) {
        
        Integer[][] dp = new Integer[grid.length][grid[0].length];
        int[] ans = new int[grid[0].length];
        
        
        
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                
                if( j == 0 && grid[i][j] == -1){
                    
                    dp[i][j] = -1;
                    continue;
                }
                
                if(j == grid[0].length - 1 && grid[i][j] == 1){
                    dp[i][j] = -1;
                    continue;
                }
                
                 if(grid[i][j] == 1 && grid[i][j + 1] == -1){
                    dp[i][j] = -1;
                    continue;
                }
                
                if(grid[i][j] == -1 && grid[i][j - 1] == 1){
                    dp[i][j] = -1;
                    continue;
                }
                
                if(i == grid.length - 1){
                    dp[i][j] = grid[i][j] == 1 ? j + 1 : j -1;
                    continue;
                }
                
                
               
                
                
            }
        }
        
        for(int i = 0; i < grid[0].length; i++){
            
           Integer res =  helper(grid, dp, 0, i);
            ans[i] = res.intValue();
        }
        
        return ans;
        
        
        
        
        
    }
}