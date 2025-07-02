class Solution {
public:

    int minSum(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        if(col<0 || col==n) return 1e9;
        if(row==n-1) return matrix[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int leftDiag=matrix[row][col]+minSum(row+1,col-1,matrix,dp);
        int down=matrix[row][col]+minSum(row+1,col,matrix,dp);
        int rightDiag=matrix[row][col]+minSum(row+1,col+1,matrix,dp);

        return dp[row][col]=min(leftDiag,min(down,rightDiag));
    }

    int space(vector<vector<int>>& matrix){
        int n=matrix.size();

        
        vector<int>next(n+1,0);
        for(int i=0;i<n;i++) {
            next[i]=matrix[n-1][i];
        }
        
        for(int row=n-2;row>=0;row--){

            vector<int>curr(n+1,0);

            for(int col=n-1;col>=0;col--){
                int leftDiag=1e9;
                int rightDiag=1e9;
                if(col-1>=0)
                    leftDiag=matrix[row][col]+next[col-1];
                int down=matrix[row][col]+next[col];
                if(col+1<n)
                    rightDiag=matrix[row][col]+next[col+1];

                curr[col]=min(leftDiag,min(down,rightDiag));
            }
            next=curr;
        }
        int mini=1e9;
        for(int i=0;i<n;i++) mini=min(mini,next[i]);
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {


        return space(matrix);
    }
};