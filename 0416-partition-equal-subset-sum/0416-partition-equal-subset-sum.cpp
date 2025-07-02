class Solution {
public:

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        
        // vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        vector<int>curr(k+1,0);
        curr[0]=1;

        for(int ind=n-1;ind>=0;ind--){
            for(int sum=k;sum>=0;sum--){
                //pick
                bool pick=false;
                bool npick=false;
                if(sum-arr[ind]>=0)
                    pick=curr[sum-arr[ind]]; 
                
                //npick
                npick=curr[sum];
                // cout<<ind<<" "<<sum<<" "<<pick<<" "<<npick<<endl;
                curr[sum]=pick | npick;
            }
        }
        return curr[k];

    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum&1) return false;
        return subsetSumToK(nums.size(),sum/2,nums);
    }
};