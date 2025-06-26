class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i=0;
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(i<n-3){
            while(i>0 && i<n-3 && nums[i]==nums[i-1]) i++;
            int j=i+1;
            while(j<n-2){
                while(j>i+1 && j<n-2 && nums[j]==nums[j-1]) j++;
                int k=j+1,l=n-1;
                while(k<l){
                    long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        int last_low=nums[k];
                        int last_high=nums[l];
                        while(k<l && nums[k]==last_low) k++;
                        while(k<l && nums[l]==last_high) l--;
                    }
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};