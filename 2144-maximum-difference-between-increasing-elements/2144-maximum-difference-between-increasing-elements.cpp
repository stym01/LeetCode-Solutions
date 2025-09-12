class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=nums[0];
        int ans=-1e9;
        for(int i=1;i<nums.size();i++){
            int x=nums[i]-mini;
            mini=min(mini,nums[i]);
            if(x<=0) continue;
            ans=max(ans,x);
        }
        if(ans==-1e9) return -1;
        return ans;
    }
};