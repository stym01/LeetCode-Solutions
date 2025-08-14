class Solution {
public:

    int floorMod(int x,int y){
        return ((x%y)+y)%y;
    }

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>>matrix(n,vector<int>(n));
        
        int d=0;
        int row=0;
        int col=0;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        int cnt=1;
        while(cnt<=n*n){
            matrix[row][col]=cnt++;

            int nrow=floorMod(row+dir[d][0],n);
            int ncol=floorMod(col+dir[d][1],n);


            if(matrix[nrow][ncol]!=0) d=(d+1)%4;

            row+=dir[d][0];
            col+=dir[d][1];
        }










        return matrix;
    }
};