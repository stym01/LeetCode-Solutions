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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};