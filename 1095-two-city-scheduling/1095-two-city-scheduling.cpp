class Solution {
public:
    
    int f(int n1,int n2,vector<vector<int>>&costs,vector<vector<int>>&dp){
        int n=costs.size();   
        int ind=n1+n2;
        if(ind==n) return 0;
        int pick1=1e9,pick2=1e9;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(n1<n/2)
            pick1=costs[ind][0]+f(n1+1,n2,costs,dp);
        if(n2<n/2)
            pick2=costs[ind][1]+f(n1,n2+1,costs,dp);
        
        return dp[n1][n2]=min(pick1,pick2);
        
        
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>dp(n/2+1,vector<int>(n/2+1,-1));
        return f(0,0,costs,dp);
    }
};