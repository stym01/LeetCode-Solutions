class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int n=s.size();
        int m=t.size();
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int startingInd=-1;
        int minLen=1e9;
        while(r<n){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            
            while(cnt==m){
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    startingInd=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
                r++;
            
        }
        cout<<minLen;
        
        if(startingInd==-1) return "";
        return s.substr(startingInd,minLen);

    }
};