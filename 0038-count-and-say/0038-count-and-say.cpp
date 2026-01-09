

class Solution {
public:

    string compress(string chars) {
        int i=0;
        int j=0;
        int n=chars.size();
        char c=chars[0];
        int cnt=0;
        string ans;
        while(j<n){
            
            while(j<n && chars[j]==c){
                cnt++;
                j++;
            }
            cout<<c<<cnt<<"<"<<j<<"\n";
            string s=to_string(cnt);

            for(int k=0;k<s.size();k++){
                ans+=s[k];
            }
            ans+=c;
            if(j<n){
                c=chars[j];
                cnt=0;
            }
        }
        cout<<ans<<"\n";
        return ans;
    }

    string countAndSay(int n) {
        string ans="1";
        cout<<ans;
        for(int i=0;i<n-1;i++){
            ans=compress(ans);
        }
        return ans;
    }
};