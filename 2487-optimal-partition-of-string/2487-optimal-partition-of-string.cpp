class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mpp;
        int n=s.size();
        int cnt=1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(mpp.find(ch)!=mpp.end()){
                cnt++;
                mpp.clear();
            }
            mpp[ch]++;
        }
        return cnt;
        

    }
};