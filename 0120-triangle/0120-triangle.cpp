class Solution {
public:

    //tc=> 2^(n*n)
    //sc=>o(n) stack space

    int f(int row,int col,int m,int n,vector<vector<int>>&grid){
        //col max j+1 tk jaayega but wo to already increase hua hai next wale row me to kabhi bhi out of boundary nhi jaayega...so sirf ek hi base case hoga...
        if(row==m-1){
            return grid[row][col];

            // return min(grid[row][col],grid[row][col+1]); ye nhi hoga kyoki already col+1 ke 
                                                          //liye call kr diya hohg prev recursion ne...
        }

        int left=INT_MAX;
        int right=INT_MAX;
        // if(row+1<m){ //bina condition ke bhi work krega kyoki row m-1 hui to return hi aajanaa hai and col+1 bhi m-1 row tk hi jaayegi...
            left=grid[row][col]+f(row+1,col,m,n+1,grid); 
        // }
        // if(col+1<n+1 && row+1<m){
            right=grid[row][col]+f(row+1,col+1,m,n+1,grid);
        // }
        return min(left,right);
    }

    //tc=> O(n*n)
    //sc=>o(n) stack space + o(n*n)

    int memo(int row,int col,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==m-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];

        int left=grid[row][col]+memo(row+1,col,m,n+1,grid,dp);
        int right=grid[row][col]+memo(row+1,col+1,m,n+1,grid,dp);

        return dp[row][col]=min(left,right);
    }

    //tc=> O(n*n)
    //sc=> o(n*n)

    int tabu(int m,vector<vector<int>>&grid){
        vector<vector<int>>dp(m,vector<int>(m,-1));

        for(int i=0;i<grid[m-1].size();i++){
            dp[m-1][i]=grid[m-1][i];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=0;j<grid[i].size();j++){

                int left=grid[i][j]+dp[i+1][j];
                int right=INT_MAX;
                if(j+1<grid[i+1].size()) //it will alwaays be so dont need to write this
                    right=grid[i][j]+dp[i+1][j+1];

                dp[i][j]=min(left,right);
            }
        }

        return dp[0][0];  
    }

    //tc=> O(n*n)
    //sc=> o(n) 

    int space(int m,vector<vector<int>>&grid){
        vector<int>prev(m);
        
        for(int i=0;i<grid[m-1].size();i++){
            prev[i]=grid[m-1][i];
        }

        for(int i=m-2;i>=0;i--){
            vector<int>curr(m);
            for(int j=0;j<grid[i].size();j++){

                int left=grid[i][j]+prev[j];
                int right=INT_MAX;
                if(j+1<grid[i+1].size())
                    right=grid[i][j]+prev[j+1];

                curr[j]=min(left,right);
            }
            prev=curr;
        }

        return prev[0];  
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();

        //triangulaar dp can be declared like yhis also to save space...
        // vector<vector<int>> dp;
        
        // for(int i=0; i<n; i++)
        // {
        //     vector<int> temp(i+1, -1);
        //     dp.push_back(temp);
        // }

        //M-1
        // return f(0,0,m,n,triangle);

        //M-2
        vector<vector<int>>dp(m,vector<int>(m,-1));
        // return memo(0,0,m,n,triangle,dp);

        //M-3
        // return tabu(m,triangle);

        //M-4
        return space(m,triangle);
    }
};