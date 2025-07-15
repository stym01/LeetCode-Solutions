class Solution {
public:

    int f(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || nums[prev]<nums[ind]){
            take=1+f(ind+1,ind,nums,dp);
        }
        int ntake=f(ind+1,prev,nums,dp);
        return dp[ind][prev+1]=max(take,ntake);
    

    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev=n-2;prev>=-1;prev--){
                int take=0;
                int ntake=0;
                if(prev==-1 || nums[prev]<nums[ind]){
                    take=1+dp[ind+1][ind+1];
                }
                ntake=dp[ind+1][prev+1];
                dp[ind][prev+1]=max(take,ntake);
            }
        }
        return dp[0][0];

        return f(0,-1,nums,dp);
    }
};