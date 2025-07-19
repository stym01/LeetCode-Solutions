class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int n=gas.size();
        int mini=-1e9;
        int ind=0;
        int tsum=0;
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            sum+=diff;
            tsum+=diff;
            if(sum<0){
                ind=i+1;
                sum=0;
            }
        }
        if(tsum<0) return -1;
        return ind;
    }
};