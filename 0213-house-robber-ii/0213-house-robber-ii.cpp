class Solution {
public:


    int tabu(vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        int n=nums.size();

        for(int i=1;i<n;i++){
            int curr=max(nums[i]+prev2,0+prev);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>temp(nums.begin(),nums.end()-1);
        vector<int>temp2(nums.begin()+1,nums.end());
        return max(tabu(temp),tabu(temp2));
    }
};