class Solution {
public:

    int f(int l,int r,vector<int>&nums,vector<vector<int>>&dp){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int left=nums[l]-f(l+1,r,nums,dp);
        int right=nums[r]-f(l,r-1,nums,dp);
        return dp[l][r]=max(left,right);

    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));


        int x= f(0,n-1,nums,dp);
        return x>=0;
    }
};