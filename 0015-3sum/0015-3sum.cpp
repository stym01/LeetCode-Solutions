class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // int i=0;
        int j=0;
        int n=nums.size();
        // int k=n-1;      
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            int k=n-1;
            while(j<k){
                int x=nums[j]+nums[k];
                x+=nums[i];
                if(x==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    cout<<i<<" "<<j<< " "<<k<<endl;
                    int last= nums[j], last_high_occurrence = nums[k];
                    while(j<k && nums[j]==last)
                    {j++;}
                    while(j<k && nums[k]==last_high_occurrence)
                    {k--;}
                }
                else if(x>0){
                    k--;
                }
                else j++;
            }
            // i++;
        }

        return ans;
    }
};