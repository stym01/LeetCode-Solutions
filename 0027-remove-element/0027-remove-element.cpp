class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        int j=0;
        while(j<n){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
                j++;
            }
            else
                j++;
        }
        return i;

    }
};