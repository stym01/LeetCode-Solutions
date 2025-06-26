class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size()-1;k++){
            int i=k+1,j=n-1;
            while(k<n-1 && nums[k]==nums[k+1]) continue;
            while(i<j){
                
                int sum=nums[i]+nums[j];
                sum+=nums[k];
                if(sum==0) {
                    vector<int>temp={nums[k],nums[i],nums[j]};
                    st.insert(temp);
                    i++;
                    j--;
                    // while(i<j &&nums[i]==nums[i+1]) {
                    //     i++;
                    // }
                    // while(i<j && nums[j]==nums[j-1]){
                    //     j--;
                    // }
                }
                else if(sum<0) i++;
                else j--;
                // cout<<'a'<<endl;
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());

        return ans;
    }
};