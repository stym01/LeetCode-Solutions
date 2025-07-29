class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt=0;
        int l=0;
        int r=0;
        int n=s.size();
        int startInd=-1;
        vector<string>ans;
        int smallest=1e9;
        while(r<n){
            if(s[r]=='1'){
                cnt++;
            }
            while(cnt==k){
                int size=r-l+1;
                if(size<=smallest){
                    if(size<smallest) ans.clear();
                    smallest=size;
                    startInd=l;
                    ans.push_back(s.substr(l,smallest));
                }
                if(s[l]=='1'){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(startInd==-1) return "";
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};