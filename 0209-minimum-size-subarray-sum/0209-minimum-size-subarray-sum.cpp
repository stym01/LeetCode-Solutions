class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=0;
        int sum=0;
        int mini=n+1;
        while(right<n){
            sum+=nums[right++];

            while(sum>=target){
                mini=min(mini,right-left);
                sum-=nums[left++];
            }
            
        }
        if(mini==n+1) return 0;
        return mini;

    }
};