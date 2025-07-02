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
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=0;i<m;i++) dp[i][n]=1e9;
        for(int i=0;i<n;i++) dp[m][i]=1e9;

        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){

                if(row==m-1 && col==n-1) continue;
                    
                int down=grid[row][col]+dp[row+1][col];
                int right=grid[row][col]+dp[row][col+1];
                dp[row][col]=min(down,right);
            }
        }
        return dp[0][0];
        return minSum(0,0,grid,dp);
    }
};