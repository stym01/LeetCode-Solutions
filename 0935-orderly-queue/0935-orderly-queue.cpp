class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        }

        string ans=s;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            string temp=s.substr(i+1,n-1)+s.substr(0,i+1);
            ans=min(ans,temp);
        }
        return ans;
        
    }
};