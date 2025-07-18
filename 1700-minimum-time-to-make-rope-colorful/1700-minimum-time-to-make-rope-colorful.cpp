class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int maxi=neededTime[0];
        int time=0;
        int n=colors.size();

        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                if(maxi>neededTime[i]){
                    time+=neededTime[i];
                }
                else{
                    time+=maxi;
                    maxi=neededTime[i];

                }
            }
            else{
                // time+=maxi;
                maxi=neededTime[i];
            }
        }
        return time;
        
    }
};