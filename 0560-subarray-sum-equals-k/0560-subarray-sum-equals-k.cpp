class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int maxi=0;
        mpp[0]=0;
        for(int i=0;i<arr.size();i++){
            // cout
            sum+=arr[i];
            int target=sum-k;
            
            if(sum==k){
                maxi++;
            }
            
            if(mpp.find(target)!=mpp.end()){
                maxi+=mpp[target];
            }
            
            // if(mpp.find(sum)==mpp.end())
            mpp[sum]++;
            
            
        }
        return maxi;


    }
};