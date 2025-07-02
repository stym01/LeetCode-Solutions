class Solution {
public:

    int minSum(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(row==m ||col==n) return 1e9;
        if(row==m-1 && col==n-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];

        int down=grid[row][col]+minSum(row+1,col,grid,dp);
        int right=grid[row][col]+minSum(row,col+1,grid,dp);
        return dp[row][col]=min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return minSum(0,0,grid,dp);
    }
};