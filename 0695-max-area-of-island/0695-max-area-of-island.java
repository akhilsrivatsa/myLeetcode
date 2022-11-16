class Solution {
    private int maxArea(int[][] grid, int i, int j){
        
        if(i < 0 || i == grid.length || j < 0 || j == grid[0].length || grid[i][j] == 0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        return 1 + maxArea(grid, i + 1, j) +  maxArea(grid, i - 1, j) + maxArea(grid, i, j + 1) + maxArea(grid, i, j - 1);
    }
    
    
    public int maxAreaOfIsland(int[][] grid) {
        
        int mxArea = 0;
        
        for(int i = 0;i < grid.length; i++){
            for(int j =0; j < grid[i].length; j++){
                
                if(grid[i][j] == 1){
                    mxArea = Math.max(maxArea(grid, i, j), mxArea);
                }
                
            }
        }
        
        return mxArea;
    }
}