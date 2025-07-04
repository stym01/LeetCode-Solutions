class Solution {
public:

    int minCoins(int ind,int rem,int n,vector<int>&coins,vector<vector<int>>&dp){
        if(rem<0) return 1e9;
        if(ind==n) return (rem==0)?0:1e9;

        if(dp[ind][rem]!=-1) return dp[ind][rem];
        //pick
        int pick=1+minCoins(ind,rem-coins[ind],n,coins,dp);
        int npick=minCoins(ind+1,rem,n,coins,dp);
        return dp[ind][rem]=min(pick,npick);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int noOfCoins=minCoins(0,amount,n,coins,dp);
        if(noOfCoins==1e9) return -1;
        return noOfCoins;
    }
};