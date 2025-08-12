class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        long long sum=0;
        int i=0;
        int j=0;
        int n=mat.size();
        while(i<n){
            sum+=mat[i][j];
            cout<<mat[i][j]<<" ";
            i++;
            j++;
        }
        j=n-1;
        i=0;
        while(j>=0){
            sum+=mat[i][j];
            cout<<mat[i][j]<<" ";
            i++;

            j--;
        }
        int sub=mat[n/2][n/2];
        if(n%2==1){
            sum-=sub;
            cout<<sub<<" ";

        }
        return sum;

    }
};