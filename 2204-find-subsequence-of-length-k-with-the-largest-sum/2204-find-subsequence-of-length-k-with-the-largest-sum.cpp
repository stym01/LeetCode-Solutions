class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }
        vector<int>a(nums.size(),0);
        while(!pq.empty()){
            int node=pq.top().second;
            a[node]=-1e6;
            pq.pop();
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(a[i]==-1e6)
                ans.push_back(nums[i]);
        }
        return ans;

    }
};