class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());

        int cnt=0;
        int maxi=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(power>=tokens[i]){
                power-=tokens[i];
                cnt++;
                ind=i;
            }
            else break;
        }
        maxi=max(maxi,cnt);
        int l=ind+1;
        int r=n-1;

        while(l<=r){
            if(power>=tokens[l]){
                cnt++;
                power-=tokens[l++];
                maxi=max(maxi,cnt);

            }
            else if(cnt>=1){
                power+=tokens[r--];
                cnt--;
            }
            else break;
        }

        return maxi;
    }
};