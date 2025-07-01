class Solution {
public:

    int f(int n,vector<int>&dp){

        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int left=f(n-1,dp);
        int right=f(n-2,dp);
        return dp[n]=left+right;
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,0);

        int prev=1;
        int sprev=1;

        for(int i=2;i<=n;i++){
            int left=prev;
            int right=sprev;
            sprev=prev;
            prev=left+right;
        }
        return prev;


        // return f(n,dp);
    }
};