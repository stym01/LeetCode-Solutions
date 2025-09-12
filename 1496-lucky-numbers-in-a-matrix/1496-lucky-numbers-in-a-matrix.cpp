class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>mini(m,0);
        vector<int>maxi(n,0);

        for(int i=0;i<m;i++){

            int mi=1e9;
            for(int j=0;j<n;j++){
                mi=min(mi,matrix[i][j]);
            }
            mini[i]=mi;
        }

        for(int j=0;j<n;j++){
            int ma=-1e9;
            for(int i=0;i<m;i++){
                ma=max(ma,matrix[i][j]);
            }
            maxi[j]=ma;
        }
        vector<int>ans;
        map<int,int>mpp;
        for(auto it:maxi) mpp[it]++;
        for(auto it:mini){
            if(mpp[it]>0) ans.push_back(it);
        }

        return ans;


    }
};