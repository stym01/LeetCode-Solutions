class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        // dp[n1],dp[n2]=0

        for(int ind1=n1-1;ind1>=0;ind1--){
            for(int ind2=n2-1;ind2>=0;ind2--){
                if(text1[ind1]==text2[ind2]) dp[ind1][ind2]=1+dp[ind1+1][ind2+1];
                else dp[ind1][ind2]=max(dp[ind1+1][ind2],dp[ind1][ind2+1]);
            }
        }
        return dp[0][0];


        // return lcs(0,0,text1,text2,dp);
    }

    int minDistance(string word1, string word2) {
        int lcs=longestCommonSubsequence(word1,word2);
        int n1=word1.size();
        int n2=word2.size();
        int del=n1-lcs;
        int ins=n2-lcs;
        return del+ins;
    }
};