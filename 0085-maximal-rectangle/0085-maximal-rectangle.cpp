class Solution {
public:

    vector<int> nextSmallerElement(vector<int> &arr, int n){

        vector<int>nse(n);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nse[i]=n;
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nse[i]=n;
                }
                else{
                    nse[i]=st.top().second;
                }
                st.push({arr[i],i});
            }
        }
        return nse;
    }

    vector<int> leftSmaller(vector<int>&arr,int n){

        vector<int>nsl(n);
        stack<pair<int,int>>st;
    
        for(int i=0;i<n;i++){
            if(st.empty()){
                nsl[i]=-1;
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i]=-1;
                }
                else{
                    nsl[i]=st.top().second;
                }
                st.push({arr[i],i});
            }
        }
        return nsl;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsr=nextSmallerElement(heights,n); //just finding the next smaller index to the right if not then assign the n index
        vector<int>nsl=leftSmaller(heights,n); //and to the left if not then assign -1 coz area waha tk lenge na
        int maxArea=-1e9;
        for(int i=0;i<n;i++){
            int area=(nsr[i]-nsl[i]-1)*heights[i];  //just subtract 1 fsrom sthr difference to get the length and mutiply with heights[i] to get area
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>temp(n,0);
        int maxi=-1e9;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') temp[j]++; //after every row, updating temp...if its 1 then add it so that the length increase but if its 0 then no lentgh hece 0
                else temp[j]=0;
            }
            int maxAreaInRow=largestRectangleArea(temp);   //just finding the max area till that row and updating maxi
            maxi=max(maxAreaInRow,maxi);
        }
        return maxi;
    }

};