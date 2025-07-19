class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>times;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
            times.push_back({growTime[i],plantTime[i]});
        }

        sort(times.begin(),times.end(),greater<pair<int,int>>());

        int plant=0;
        int maxi=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,plant+times[i].second+times[i].first);
            plant+=times[i].second;
        }

        return maxi;

    }
};