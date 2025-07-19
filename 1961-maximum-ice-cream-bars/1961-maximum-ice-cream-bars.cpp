class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi=0;
        for(auto it:costs) maxi=max(maxi,it);
        vector<int>count(maxi+1,0);

        for(auto it:costs){
            count[it]++;
        }
        int cnt=0;
        for(int i=0;i<=maxi;i++){
            if(count[i]>0){
                if(coins>=((long)i*count[i])){
                    cnt+=count[i];
                    coins=coins-(i*count[i]);
                }
                else{
                    int x=coins/i;
                    cnt+=x;
                    break;
                    
                }
            }
        }
        return cnt;

    }
};