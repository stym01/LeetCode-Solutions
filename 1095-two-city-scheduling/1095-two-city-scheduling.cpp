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
    
    bool static comp(vector<int>&a,vector<int>&b){
        int ua=a[0];
        int ub=a[1];

        int va=b[0];
        int vb=b[1];

        if(ua-ub<va-vb) return 1;
        return 0;

    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int sum=0;

        sort(costs.begin(),costs.end(),comp);


        for(int i=0;i<n/2;i++){
            sum+=costs[i][0];
        }

        
        for(int i=n/2;i<n;i++){
            sum+=costs[i][1];
        }
        return sum;


    }
};