class Solution {
public:

    int f(int ind,int bought,vector<int>&prices,int n, vector<vector<int>>&dp){
        if(ind==n) {
            if(bought) return -1e9;
            return 0;
        }
        int maxi=0;
        if(dp[ind][bought]!=-1) return dp[ind][bought];

        
        if(bought){
            maxi=max(maxi,f(ind+1,0,prices,n,dp)+prices[ind]);
        }
        else{
            maxi=max(maxi,f(ind+1,1,prices,n,dp)-prices[ind]);
        }

        maxi=max(maxi,f(ind+1,bought,prices,n,dp));

        return dp[ind][bought]=maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,prices,n,dp);
    }
    
};