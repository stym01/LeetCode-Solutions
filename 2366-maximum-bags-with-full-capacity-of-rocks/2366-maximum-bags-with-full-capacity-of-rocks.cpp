class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        int cnt=0;
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            if(additionalRocks-diff[i]>=0){
                cnt++;
                additionalRocks-=diff[i];
            }
            else break;
        }
        return cnt;
    }
};