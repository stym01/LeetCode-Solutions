class Solution {
public:

    long long times(long long x,vector<int>& time){
        long long cnt=0;
        for(int i=0;i<time.size();i++){
            if(time[i]<=x) cnt+=x/time[i];
            else break;
        }
        return cnt;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        int n=time.size();
        sort(time.begin(),time.end());
        long long maxTime=(long)time[0]*totalTrips;
        long long low=1;
        long long high=maxTime;
        long long ans=high;
        while(low<=high){
            long long mid=(low+high)/2;
            if(times(mid,time)<totalTrips){
                low=mid+1;
            }
            else{
                ans=min(ans,mid);
                high=mid-1;
            }
        }
        return ans;

        
    }
};