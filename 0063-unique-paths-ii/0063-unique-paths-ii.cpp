class Solution {
public:

    int uniquePaths(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(row==m || col==n) return 0;
        if(grid[row][col]==1) return 0;
        if(row==m-1 && col==n-1) return 1;

        if(dp[row][col]!=-1) return dp[row][col];

        int down=uniquePaths(row+1,col,grid,dp);
        int right=uniquePaths(row,col+1,grid,dp);
        return dp[row][col]=down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // dp[m-1][n-1]=1;

        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(obstacleGrid[row][col]==1) continue;
                if(row==m-1 && col==n-1) {
                    dp[row][col]=1;
                    continue;
                }

                int down=dp[row+1][col];
                int right=dp[row][col+1];
                dp[row][col]=(long)down+(long)right;

            }
        }

        return dp[0][0];





        return uniquePaths(0,0,obstacleGrid,dp);
    }
};