class Solution {
public:

    int f(int ind,int bought,int times,vector<int>&prices,int n, vector<vector<vector<int>>>&dp){
        if(times==1) return 0;
        if(ind==n) {
            if(bought) return -1e9;
            if(times==0) return -1e9;
            return 0;
        }
        int maxi=0;
        if(dp[ind][bought][times]!=-1) return dp[ind][bought][times];
        if(bought){
            maxi=max(maxi,f(ind+1,0,1,prices,n,dp)+prices[ind]);
            maxi=max(maxi,f(ind+1,1,times,prices,n,dp));
        }
        else{
            maxi=max(maxi,f(ind+1,1,times,prices,n,dp)-prices[ind]);
            maxi=max(maxi,f(ind+1,0,times,prices,n,dp));
        }
        return dp[ind][bought][times]=maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0,prices,n,dp);
    }
};