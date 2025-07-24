class Solution {
private: long long bestTimeForThisLap[1001];
int maxLapsByAny=0;
public:

    int f(int n,int changeTime,vector<long long>&dp){
        if(n==0) return -changeTime;

        long long mini=1e9;
        if(dp[n]!=-1) return dp[n];

        for(int lap=1;lap<=n;lap++){
            long long time=bestTimeForThisLap[lap]+changeTime+f(n-lap,changeTime,dp);
            mini=min(mini,time);
        }
        return dp[n]=mini;


    }

    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        for(int i=0;i<=numLaps;i++) bestTimeForThisLap[i]=1e9;

        for(auto it:tires){
            int fi=it[0];
            int ri=it[1];
            long long currLapTime=fi; //time for single lap
            long long time=fi; //total time till this succession

            for(int lap=1;lap<=numLaps;lap++){
                if(currLapTime>fi+changeTime) break;

                if(time<bestTimeForThisLap[lap]){
                    bestTimeForThisLap[lap]=time;
                }

                currLapTime*=ri; //iss lap me kitna time lagega

                time+=currLapTime; //abhi tk kitna time laga

            }
        }

        vector<long long>dp(numLaps+1,-1);
        return f(numLaps,changeTime,dp);

    }
};