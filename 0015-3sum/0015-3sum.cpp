class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        while(i<n-2){
            if(i>0 && nums[i]==nums[i-1]) {
                i++;
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j];
                sum+=nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    int last_low=nums[j];
                    int last_high=nums[k];
                    while(j<k && nums[j]==last_low) j++;
                    while(j<k && nums[k]==last_high) k--;
                }
            }
            i++;
        }
        return ans;
    }

};