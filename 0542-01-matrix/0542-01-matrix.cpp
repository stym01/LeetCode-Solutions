class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>ans(m,vector<int>(n,1e9));
        vector<vector<int>>vis(m,vector<int>(n,0));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){

                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                ans[row][col]=min(dist,ans[row][col]);

                for(int k=0;k<4;k++){
                    int nrow=row+delrow[k];
                    int ncol=col+delcol[k];

                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && mat[nrow][ncol]==1 && vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }

                }   



            }
            dist++;
        }
        return ans;

    }
};