class Solution {
public:

    int lcs(int i,int j,string s,string t,int m,int n,vector<vector<int>>&dp){
    
        if(j==n) return 1;
        if(i==m) return 0;
        int sum=0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            sum+=lcs(i+1,j+1,s,t,m,n,dp);
        }
        sum+=lcs(i+1,j,s,t,m,n,dp);
        return dp[i][j]=sum;


    }

    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            dp[i][n]=1;
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n;j>=0;j--){
                int sum=0;
                if(s[i]==t[j]){
                    sum+=dp[i+1][j+1];
                }
                sum=(long)sum+dp[i+1][j];
                dp[i][j]=sum;
            }
        }

        return dp[0][0];








        return lcs(0,0,s,t,m,n,dp);
    }
};