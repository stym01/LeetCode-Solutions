class Solution {
public:

    int f(int ind1,int ind2,string&s,string&p,vector<vector<int>>&dp){
        int n1=s.size();
        int n2=p.size();
        
        if(ind1==n1 && ind2==n2) return true;
        // if(ind2==n2 && ind1<n1) return false;
        if(ind1==n1){
            for(int i=ind2;i<n2;i++){
                if(p[i]!='*') return false;
            }
            return true; 
        }
        if(ind1==n1 || ind2==n2) return false;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s[ind1]==p[ind2]){
            return dp[ind1][ind2]=f(ind1+1,ind2+1,s,p,dp);
        }
        else{
            if(p[ind2]=='?'){
                return dp[ind1][ind2]=f(ind1+1,ind2+1,s,p,dp);
            }
            else if(p[ind2]=='*'){
                // for(int i=ind1-1;i<n1;i++){
                //     if(f(i+1,ind2+1,s,p)) return true;
                // } 
                bool x=f(ind1+1,ind2,s,p,dp);
                bool y=f(ind1,ind2+1,s,p,dp);
                return dp[ind1][ind2]=x|y;
            }
        }
        return dp[ind1][ind2]=false;

    }

    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(0,0,s,p,dp);
    }
};