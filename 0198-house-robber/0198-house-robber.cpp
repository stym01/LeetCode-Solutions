class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

    vector<int>next(2,0);    
    vector<int>curr(2,0);


    next[0]=0;    
    next[1]=0;
    
    curr[0]=0;    
    curr[1]=0;



    for(int ind=n-1;ind>=0;ind--){
        for(int taken=0;taken<2;taken++){
            int take=-1e9;
            if(!taken){
                take= nums[ind]+ next[1];
            }
            int notTake= next[0];

            curr[taken]=max(take,notTake);
        }
        next=curr;
    }
    return curr[0];
    }
};