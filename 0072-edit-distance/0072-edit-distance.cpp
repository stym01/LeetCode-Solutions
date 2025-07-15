class Solution {
public:

    int f(int ind1,int ind2,string &word1,string &word2,vector<vector<int>>&dp){
        int n1=word1.size();
        int n2=word2.size();
        if(ind1==word1.size()) return n2-ind2 ;
        if(ind2==word2.size()) return n1-ind1;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int mini=1e9;
        cout<<ind1<<" "<<ind2<<" "<<mini<<endl;

        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2]=f(ind1+1,ind2+1,word1,word2,dp);
        }
        else{
            int replace=1+f(ind1+1,ind2+1,word1,word2,dp);
            int del=1+f(ind1+1,ind2,word1,word2,dp);
            int ins=1+f(ind1,ind2+1,word1,word2,dp);
            mini=min(replace,min(del,ins));
        }
        
        return dp[ind1][ind2]=mini;
    }

    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(0,0,word1,word2,dp);
    }
};