class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp; //using unordered map
        for(int i=0;i<n;i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                return {i,mpp[target-nums[i]]};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
 
};