class Solution {
public:

    int mod=1e9+7;
    int f(int zero,int one,int limit,bool zer,vector<vector<vector<int>>>&dp){
        if(zero==0 && one==0) return 1;

        if(dp[zero][one][zer]!=-1) return dp[zero][one][zer];

        int ans=0;
        if(zer){
            for(int i=1;i<=min(one,limit);i++) ans=(ans+f(zero,one-i,limit,false,dp)%mod)%mod;
        }
        else{
            for(int i=1;i<=min(zero,limit);i++) ans=(ans+f(zero-i,one,limit,true,dp)%mod)%mod;
        }
        return dp[zero][one][zer]=ans%mod;
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        
        vector<vector<vector<int>>>dp(zero+1,vector<vector<int>>(one+1,vector<int>(3,-1)));
        int ans=0;
        int a=f(zero,one,limit,1,dp);
        int b=f(zero,one,limit,0,dp);
        return (a+b)%mod;
    }
};