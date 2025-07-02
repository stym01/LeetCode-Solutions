class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,1);
        vector<int>prefix(n,1);
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(i==0) continue;
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) continue;
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};