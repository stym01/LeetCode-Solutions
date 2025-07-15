class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

       vector<int>dp(n,1);
       sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        int ind=n-1;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxi){
                ind=i;
                break;
            }
        }
        int len=maxi;
        cout<<len;
        while(ind>=0){
            if((dp[ind]==len) && (ans.empty() || (ans.back()%nums[ind]==0) || 0)){
                ans.push_back(nums[ind]);
                len--;
                ind--;
            }
            else{
                ind--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};