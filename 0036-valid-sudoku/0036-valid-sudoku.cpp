class Solution {
public:

    bool f(int sr,int sd,int er,int ed,vector<vector<char>>&board){
        if(er>9 || ed>9) return true;
        map<int,int>mpp;
        for(int i=sr;i<=er;i++){
            for(int j=sd;j<=ed;j++){
                char c=board[i][j];
                if(c!='.'){
                    mpp[c]++;
                    if(mpp[c]>1) return false;
                }
            }
        }

        bool x=f(sr+3,sd,er+3,ed,board);
        bool y=f(sr,sd+3,er,ed+3,board);
        return x&y;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
        map<int,int>mpp;

            for(int j=0;j<board[0].size();j++){
                char c=board[i][j];
                mpp[c]++;
                if(c!='.') {
                    if(mpp[c]>1) return false;
                }
            }
        }
        

        for(int i=0;i<board.size();i++){
        map<int,int>mpp;

            for(int j=0;j<board[0].size();j++){
                char c=board[j][i];
                mpp[c]++;
                if(c!='.') {
                    if(mpp[c]>1) return false;
                }
            }
        }
        return f(0,0,2,2,board);
        return true;
    }
};