class Solution {
public:

    int f(int l,int r,vector<int>&nums){
        if(l>r) return 0;

        int left=nums[l]-f(l+1,r,nums);
        int right=nums[r]-f(l,r-1,nums);
        return max(left,right);

    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int x= f(0,n-1,nums);
        
        return x>=0;
    }
};