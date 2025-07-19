class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int>mpp;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            mpp[tasks[i]]++;
        }
        int cnt=0;
        for(auto it:mpp){
            int val=it.first;
            int count=it.second;
            if(count==1) return -1;

            if(count%3==0)
                cnt+=count/3;
            else cnt+=count/3+1;
        }
        return cnt;

    }
};