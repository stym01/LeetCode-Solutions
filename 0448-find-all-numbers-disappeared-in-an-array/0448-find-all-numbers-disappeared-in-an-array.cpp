class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            int x=abs(it);
            if(nums[x-1]>0)
                nums[x-1]*=-1;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0) ans.push_back(i+1);
        }
        return ans;
    }
};